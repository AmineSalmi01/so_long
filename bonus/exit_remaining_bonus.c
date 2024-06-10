/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_remaining_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:51:39 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/11 00:20:42 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	close_player(t_game *game)
{
	if (game->player_t_right)
		mlx_delete_texture(game->player_t_right);
	if (game->player_right)
		mlx_delete_image(game->mlx, game->player_right);
	if (game->player_t_left)
		mlx_delete_texture(game->player_t_left);
	if (game->player_left)
		mlx_delete_image(game->mlx, game->player_left);
	if (game->player_t_up)
		mlx_delete_texture(game->player_t_up);
	if (game->player_up)
		mlx_delete_image(game->mlx, game->player_up);
	if (game->player_t_down)
		mlx_delete_texture(game->player_t_down);
	if (game->player_down)
		mlx_delete_image(game->mlx, game->player_down);
}

void	close_coins_frame2(t_game *game)
{
	if (game->frame.coins_t_frame5)
		mlx_delete_texture(game->frame.coins_t_frame5);
	if (game->frame.coins_frame5)
		mlx_delete_image(game->mlx, game->frame.coins_frame5);
	if (game->frame.coins_t_frame6)
		mlx_delete_texture(game->frame.coins_t_frame6);
	if (game->frame.coins_frame6)
		mlx_delete_image(game->mlx, game->frame.coins_frame6);
	if (game->frame.coins_t_frame7)
		mlx_delete_texture(game->frame.coins_t_frame7);
	if (game->frame.coins_frame7)
		mlx_delete_image(game->mlx, game->frame.coins_frame7);
	if (game->frame.coins_t_frame8)
		mlx_delete_texture(game->frame.coins_t_frame8);
	if (game->frame.coins_frame8)
		mlx_delete_image(game->mlx, game->frame.coins_frame8);
}

void	close_coins_frame(t_game *game)
{
	if (game->frame.coins_t_frame2)
		mlx_delete_texture(game->frame.coins_t_frame2);
	if (game->frame.coins_frame2)
		mlx_delete_image(game->mlx, game->frame.coins_frame2);
	if (game->frame.coins_t_frame3)
		mlx_delete_texture(game->frame.coins_t_frame3);
	if (game->frame.coins_frame3)
		mlx_delete_image(game->mlx, game->frame.coins_frame3);
	if (game->frame.coins_t_frame4)
		mlx_delete_texture(game->frame.coins_t_frame4);
	if (game->frame.coins_frame4)
		mlx_delete_image(game->mlx, game->frame.coins_frame4);
	close_coins_frame2(game);
}

void	exit_close(t_game *game)
{
	if (game->player_position.x_position == game->exit_position.x_position
		&& game->player_position.y_position == game->exit_position.y_position
		&& game->count_coins == 0)
		close_game(game);
}

void	enemy_close(t_game *game)
{
	if (game->player_position.x_position == game->enemy_position.x_position
		&& game->player_position.y_position == game->enemy_position.y_position)
		close_game(game);
}
