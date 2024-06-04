/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:17:06 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/04 21:39:18 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_player(t_game *game, int i, int j)
{
    if (mlx_image_to_window(game->mlx, game->player, j * 40, i * 40) < 0)
        close_game(game);
    game->player_position.x_position = j;
    game->player_position.y_position = i;
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

void print_exit(t_game *game, int i, int j)
{
    if (game->count_coins == 0)
    {
        if (mlx_image_to_window(game->mlx, game->exit, j * 40, i * 40) < 0)
            close_game(game);
    }
}

void    print_map(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (mlx_image_to_window(game->mlx, game->ground, j * 40, i * 40) < 0)
                close_game(game);
            if (game->map[i][j] == '1')
                print_wall(game, i, j);
            if (game->map[i][j] == 'P')
                print_player(game, i, j);
            if (game->map[i][j] == 'C')
                print_coins(game, i, j);
            if (game->map[i][j] == 'E')
                print_exit(game, i, j);
            j++;
        }
        i++;
    }
}