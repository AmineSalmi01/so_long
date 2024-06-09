/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:57:58 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/09 23:30:27 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_gound_and_wall(t_game *game)
{
	game->ground_t = mlx_load_png(PATH_GROUND);
	if (!game->ground_t)
	{
		game->err_exit++;
		close_game(game);
	}
	game->ground = mlx_texture_to_image(game->mlx, game->ground_t);
	if (!game->ground_t)
	{
		game->err_exit++;
		close_game(game);
	}
	game->wall_t = mlx_load_png(PATH_WALL);
	if (!game->wall_t)
	{
		game->err_exit++;
		close_game(game);
	}
	game->wall = mlx_texture_to_image(game->mlx, game->wall_t);
	if (!game->wall)
	{
		game->err_exit++;
		close_game(game);
	}
}

void	load_coins_and_exit(t_game *game)
{
	game->coins_t = mlx_load_png(PATH_COINS);
	if (!game->coins_t)
	{
		game->err_exit++;
		close_game(game);
	}
	game->coins = mlx_texture_to_image(game->mlx, game->coins_t);
	if (!game->coins)
	{
		game->err_exit++;
		close_game(game);
	}
	game->exit_t = mlx_load_png(PATH_EXIT);
	if (!game->exit_t)
	{
		game->err_exit++;
		close_game(game);
	}
	game->exit = mlx_texture_to_image(game->mlx, game->exit_t);
	if (!game->exit)
	{
		game->err_exit++;
		close_game(game);
	}
}

void	load_player_remaining(t_game *game)
{
	game->player_t_up = mlx_load_png(PATH_PLAYER_UP);
	if (!game->player_t_up)
	{
		game->err_exit++;
		close_game(game);
	}
	game->player_up = mlx_texture_to_image(game->mlx, game->player_t_up);
	if (!game->player_up)
	{
		game->err_exit++;
		close_game(game);
	}
	game->player_t_down = mlx_load_png(PATH_PLAYER_DOWN);
	if (!game->player_t_down)
	{
		game->err_exit++;
		close_game(game);
	}
	game->player_down = mlx_texture_to_image(game->mlx, game->player_t_down);
	if (!game->player_down)
	{
		game->err_exit++;
		close_game(game);
	}
}

void	load_player(t_game *game)
{
	game->player_t_Right = mlx_load_png(PATH_PLAYER_RIGHT);
	if (!game->player_t_Right)
	{
		game->err_exit++;
		close_game(game);
	}
	game->player_right = mlx_texture_to_image(game->mlx, game->player_t_Right);
	if (!game->player_right)
	{
		game->err_exit++;
		close_game(game);
	}
	game->player_t_left = mlx_load_png(PATH_PLAYER_LEFT);
	if (!game->player_t_left)
	{
		game->err_exit++;
		close_game(game);
	}
	game->player_left = mlx_texture_to_image(game->mlx, game->player_t_left);
	if (!game->player_left)
	{
		game->err_exit++;
		close_game(game);
	}
	load_player_remaining(game);
}
