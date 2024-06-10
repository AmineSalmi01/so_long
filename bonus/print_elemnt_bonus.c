/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:09:56 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/11 00:15:55 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_player(t_game *game, struct mlx_key_data keydata, int i, int j)
{
	keydata.key = 1;
	if (mlx_image_to_window(game->mlx, game->player_start, j * 40, i * 40) < 0)
		close_game(game);
	game->player_position.x_position = j;
	game->player_position.y_position = i;
}

void	print_enemy(t_game *game, int i, int j)
{
	if (mlx_image_to_window(game->mlx, game->enemy, j * 40, i * 40) < 0)
		close_game(game);
	game->enemy_position.x_position = j;
	game->enemy_position.y_position = i;
}

void	print_wall(t_game *game, int i, int j)
{
	if (mlx_image_to_window(game->mlx, game->wall, j * 40, i * 40) < 0)
		close_game(game);
}

void	print_coins(t_game *game, int i, int j)
{
	if (mlx_image_to_window(game->mlx, game->coins, j * 40, i * 40) < 0)
		close_game(game);
}

void	print_exit(t_game *game)
{
	if (game->count_coins == 0)
	{
		if (mlx_image_to_window(game->mlx, game->exit,
				game->exit_position.x_position * 40,
				game->exit_position.y_position * 40) < 0)
			close_game(game);
	}
}
