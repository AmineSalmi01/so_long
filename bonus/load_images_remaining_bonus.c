/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_remaining_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:05:57 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/09 22:19:55 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_enemy(t_game *game)
{
	game->enemy_t = mlx_load_png(PATH_PLAYER_ENEMY);
	if (!game->enemy_t)
	{
		game->err_exit++;
		close_game(game);
	}
	game->enemy = mlx_texture_to_image(game->mlx, game->enemy_t);
	if (!game->enemy)
	{
		game->err_exit++;
		close_game(game);
	}
	game->coins_tmp = mlx_texture_to_image(game->mlx, game->coins_t);
	if (!game->coins_tmp)
	{
		game->err_exit++;
		close_game(game);
	}
}
