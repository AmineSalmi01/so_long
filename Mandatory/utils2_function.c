/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 00:03:06 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/10 14:36:07 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

void	position_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->copy_map[i])
	{
		j = 0;
		while (game->copy_map[i][j])
		{
			if (game->copy_map[i][j] == 'P')
			{
				game->x_p = j;
				game->y_p = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

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

void	print_moves(t_game *game)
{
	game->move_counter++;
	write(1, "Move : ", 8);
	ft_putnbr_fd(game->move_counter, 1);
	write(1, "\n", 1);
}

void	win_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	close_game(game);
}
