/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frams_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:53:12 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/10 21:58:57 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_frame_and_texture(t_game *game, mlx_texture_t **texture,
		mlx_image_t **frame, char *path)
{
	*texture = mlx_load_png(path);
	if (!*texture)
	{
		game->err_exit++;
		close_game(game);
	}
	*frame = mlx_texture_to_image(game->mlx, *texture);
	if (!*frame)
	{
		game->err_exit++;
		close_game(game);
	}
}

void	load_frame2(t_game *game)
{
	load_frame_and_texture(game, &game->frame.coins_t_frame3,
		&game->frame.coins_frame3, PATH_COINS_FRAME3);
	load_frame_and_texture(game, &game->frame.coins_t_frame4,
		&game->frame.coins_frame4, PATH_COINS_FRAME4);
}

void	load_frame3(t_game *game)
{
	load_frame_and_texture(game, &game->frame.coins_t_frame5,
		&game->frame.coins_frame5, PATH_COINS_FRAME5);
	load_frame_and_texture(game, &game->frame.coins_t_frame6,
		&game->frame.coins_frame6, PATH_COINS_FRAME6);
}

void	load_frame4(t_game *game)
{
	load_frame_and_texture(game, &game->frame.coins_t_frame7,
		&game->frame.coins_frame7, PATH_COINS_FRAME7);
	load_frame_and_texture(game, &game->frame.coins_t_frame8,
		&game->frame.coins_frame8, PATH_COINS_FRAME8);
}

void	load_frame(t_game *game)
{
	load_frame_and_texture(game, &game->frame.coins_t_frame2,
		&game->frame.coins_frame2, PATH_COINS_FRAME2);
	load_frame2(game);
	load_frame3(game);
	load_frame4(game);
}
