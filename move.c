/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:37:38 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/05 22:47:38 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void exit_close(t_game *game)
{
    if (game->player_position.x_position == game->exit_position.x_position && 
    game->player_position.y_position == game->exit_position.y_position && game->count_coins == 0)
        close_game(game);
}
void vertical(struct mlx_key_data keydata, t_game *game)
{
    if (keydata.key == MLX_KEY_W)
    {
        if (game->map[game->player_position.y_position - 1][game->player_position.x_position] != '1')
        {
            if (game->map[game->player_position.y_position - 1][game->player_position.x_position] == 'C')
                (game->count_coins)--;
            game->map[game->player_position.y_position][game->player_position.x_position] = '0';
            game->map[game->player_position.y_position - 1][game->player_position.x_position] = 'P';
        }
    }
    if (keydata.key == MLX_KEY_S)
    {
        if (game->map[game->player_position.y_position + 1][game->player_position.x_position] != '1')
        {
            if (game->map[game->player_position.y_position + 1][game->player_position.x_position] == 'C')
                (game->count_coins)--;
            game->map[game->player_position.y_position][game->player_position.x_position] = '0';
            game->map[game->player_position.y_position + 1][game->player_position.x_position] = 'P';
        }
    }
    print_map(game);
}

void horizontal(struct mlx_key_data keydata, t_game *game)
{
    if (keydata.key == MLX_KEY_D)
    {
        if (game->map[game->player_position.y_position][game->player_position.x_position + 1] != '1')
        {
            if (game->map[game->player_position.y_position][game->player_position.x_position + 1] == 'C')
                (game->count_coins)--;
            game->map[game->player_position.y_position][game->player_position.x_position] = '0';
            game->map[game->player_position.y_position][game->player_position.x_position + 1] = 'P';
        }
    }
    if (keydata.key == MLX_KEY_A)
    {
        if (game->map[game->player_position.y_position][game->player_position.x_position - 1] != '1')
        {
            if (game->map[game->player_position.y_position][game->player_position.x_position - 1] == 'C')
                (game->count_coins)--;
            game->map[game->player_position.y_position][game->player_position.x_position] = '0';
            game->map[game->player_position.y_position][game->player_position.x_position - 1] = 'P';
        }
    }
    print_map(game);
}

int move_processing(struct mlx_key_data keydata, void  *param)
{
    t_game *game;

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
    return (1);
}
