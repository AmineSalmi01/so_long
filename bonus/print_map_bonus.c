/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:17:06 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/11 01:17:52 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_direction(t_game *game, struct mlx_key_data keydata)
{
	if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
	{
		game->player_start = game->player_right;
	}
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
	{
		game->player_start = game->player_left;
	}
	else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
	{
		game->player_start = game->player_up;
	}
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
	{
		game->player_start = game->player_down;
	}
}

void	exit_position(t_game *game, int i, int j)
{
	game->exit_position.x_position = j;
	game->exit_position.y_position = i;
}

void	draw_map(t_game *game, struct mlx_key_data keydata, int i, int j)
{
	if (game->map[i][j] != '1')
	{
		if (mlx_image_to_window(game->mlx, game->ground, j * 40, i * 40) < 0)
			close_game(game);
	}
	handle_direction(game, keydata);
	if (game->map[i][j] == '1')
		print_wall(game, i, j);
	if (game->map[i][j] == 'P')
		print_player(game, keydata, i, j);
	if (game->map[i][j] == 'C')
		print_coins(game, i, j);
	if (game->map[i][j] == 'E')
		exit_position(game, i, j);
	if (game->map[i][j] == 'H')
		print_enemy(game, i, j);
}

void	draw_row(t_game *game, struct mlx_key_data keydata, int i)
{
	int	j;

	j = 0;
	while (game->map[i][j])
	{
		draw_map(game, keydata, i, j);
		j++;
	}
}

void	print_map(t_game *game, struct mlx_key_data keydata)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		draw_row(game, keydata, i);
		i++;
	}
	print_exit(game);
}
