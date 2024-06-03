/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:37:38 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/03 23:19:05 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void vertical(struct mlx_key_data keydata, t_game *game)
{
    printf("the pos player is :\n%d\n%d\n", game->player_position.x_position, game->player_position.y_position);
    if (keydata.key == MLX_KEY_W)
    {
        if (game->map[game->player_position.y_position - 1][game->player_position.x_position] != '1')
        {
            game->map[game->player_position.y_position][game->player_position.x_position] = '0';
            game->map[game->player_position.y_position - 1][game->player_position.x_position] = 'P';
        }
    }
}

int move_processing(struct mlx_key_data keydata, void  *param)
{
    t_game *game;
    
    game = (t_game *)param;
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
        vertical(keydata, game);
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
        puts("d");
    if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
        puts("a");
    if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
        puts("s");
    print_map(game);
    return (1);
}