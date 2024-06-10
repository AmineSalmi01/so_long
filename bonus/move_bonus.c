/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:37:38 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/10 22:47:23 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'C')
			(game->count_coins)--;
		game->map[game->player_position.y_position]
		[game->player_position.x_position] = '0';
		game->map[new_y][new_x] = 'P';
		game->player_position.x_position = new_x;
		game->player_position.y_position = new_y;
		print_moves(game);
	}
}

void	vertical(struct mlx_key_data keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_W)
	{
		move_player(game, game->player_position.x_position,
			game->player_position.y_position - 1);
	}
	if (keydata.key == MLX_KEY_S)
	{
		move_player(game, game->player_position.x_position,
			game->player_position.y_position + 1);
	}
	print_map(game, keydata);
}

void	horizontal(struct mlx_key_data keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_D)
	{
		move_player(game, game->player_position.x_position + 1,
			game->player_position.y_position);
	}
	if (keydata.key == MLX_KEY_A)
	{
		move_player(game, game->player_position.x_position - 1,
			game->player_position.y_position);
	}
	print_map(game, keydata);
}

int	move_processing(struct mlx_key_data keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		vertical(keydata, game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		horizontal(keydata, game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		horizontal(keydata, game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		vertical(keydata, game);
	if (keydata.key == MLX_KEY_ESCAPE)
		close_game(game);
	exit_close(game);
	enemy_close(game);
	return (1);
}
