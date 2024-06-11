/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:37:38 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/11 01:53:55 by asalmi           ###   ########.fr       */
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
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
	{
		move_player(game, game->player_position.x_position,
			game->player_position.y_position - 1);
	}
	if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
	{
		move_player(game, game->player_position.x_position,
			game->player_position.y_position + 1);
	}
	print_map(game, keydata);
}

void	horizontal(struct mlx_key_data keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
	{
		move_player(game, game->player_position.x_position + 1,
			game->player_position.y_position);
	}
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
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
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		vertical(keydata, game);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		horizontal(keydata, game);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		horizontal(keydata, game);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		vertical(keydata, game);
	if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
		close_game(game);
	exit_close(game);
	enemy_close(game);
	return (1);
}
