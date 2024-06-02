/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:43:36 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/02 10:41:13 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int count_element(char **map, char c)
{
    int i;
    int j;
    int counter;

    i = 0;
    counter = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == c)
                counter++;
            j++;
        }
        i++;
    }
    return (counter);
}

void    lenght_map(t_game *game)
{
    game->size_x = 0;
    game->size_y = 0;
    while (game->map[game->size_y])
    {
        if (game->size_y == 0)
        {
            while (game->map[game->size_y][(game->size_x) + 1])
                (game->size_x)++;
        }
        (game->size_y)++;
    }
}
