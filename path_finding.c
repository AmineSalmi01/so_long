/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:04:35 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/06 00:51:32 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// void flood_fill(t_game *game, int x, int y) 
// {
//     if (game->copy_map[y][x] == '1')
//             return ;
//     if (game->copy_map[y][x] == 'C')
//     {
//         (game->check_c)++;
//         game->copy_map[y][x] = '1';
//     }
//     if (game->copy_map[y][x] == 'E')
//     {
//         (game->check_e)++;
//         game->copy_map[y][x] = '1';
//     }
//     game->copy_map[y][x] = '1';
    
//     flood_fill(game, x + 1, y);
//     flood_fill(game, x - 1, y);
//     flood_fill(game, x, y + 1);
//     flood_fill(game, x, y - 1);
// }