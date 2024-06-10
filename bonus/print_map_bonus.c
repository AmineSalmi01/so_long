/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:17:06 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/09 22:05:23 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void print_player(t_game *game, struct mlx_key_data keydata, int i, int j)
{
    keydata.key = 1;
    if (mlx_image_to_window(game->mlx, game->player_start, j * 40, i * 40) < 0)
        close_game(game);
    game->player_position.x_position = j;
    game->player_position.y_position = i;
}
void handle_direction(t_game *game, struct mlx_key_data keydata)
{
    if (keydata.key == MLX_KEY_D)
    {
        game->player_start = game->player_right;
    }
    else if (keydata.key == MLX_KEY_A)
    {
        game->player_start = game->player_left;
    }
    else if (keydata.key == MLX_KEY_W)
    {
        game->player_start = game->player_up;
    }
    else if (keydata.key == MLX_KEY_S)
    {
        game->player_start = game->player_down;
    }
}

void print_enemy(t_game *game, int i, int j)
{
    if (mlx_image_to_window(game->mlx, game->enemy, j * 40, i * 40) < 0)
        close_game(game);
    game->enemy_position.x_position = j;
    game->enemy_position.y_position = i;
}

void print_wall(t_game *game, int i, int j)
{
    if (mlx_image_to_window(game->mlx, game->wall, j * 40, i * 40) < 0)
        close_game(game);
}

void print_coins(t_game *game, int i, int j)
{
    if (mlx_image_to_window(game->mlx, game->coins, j * 40, i * 40) < 0)
        close_game(game);
}

void print_exit(t_game *game)
{
    if (game->count_coins == 0)
    {
        if (mlx_image_to_window(game->mlx, game->exit, game->exit_position.x_position  * 40, game->exit_position.y_position  * 40) < 0)
            close_game(game);
    }
}
void exit_position(t_game *game, int i, int j)
{
    game->exit_position.x_position = j;
    game->exit_position.y_position = i;
}

void    print_map(t_game *game, struct mlx_key_data keydata)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
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
            j++;
        }
        i++;
    }
    print_exit(game);
}
