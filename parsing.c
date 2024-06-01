/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:42:24 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/01 21:27:47 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_extension(char *arg)
{
    char *str;
    int len_arg;
    int len_str;
    int fd;

    str = ".ber";
    len_arg = ft_strlen(arg) - 1;
    len_str = ft_strlen(str) - 1;
    fd = open(arg, O_RDONLY);
    if (fd < 0)
        put_message("Error\nCheck your file !\n", 2);
    if (len_arg <= len_str)
        put_message("Error\nCheck your file !\n", 2);
    while (len_arg > 0 && len_str > 0)
    {
        if (arg[len_arg--] != str[len_str--])
            put_message("Error\nCheck your file !\n", 2);
    }
    close(fd);
}
void validate_elements(t_game *game)
{
    int i;
    int j;
    
    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] != '1' &&
                game->map[i][j] != '0' && 
                game->map[i][j] != 'C' && 
                game->map[i][j] != 'E' && 
                game->map[i][j] != 'P' && 
                game->map[i][j] != '\n')
                put_message("Error\nInvalid element in the map!\n", 2);
            j++;
        }
        i++;
    }
}

void check_elemnts(t_game *game)
{
    if (count_element(game->map, 'P') != 1)
        put_message("Error\nMap should contain one 'Player'!\n", 2);
    if (count_element(game->map, 'E') != 1)
        put_message("Error\nMap should contain one 'Exit'!\n", 2);
    if (!count_element(game->map, 'C'))
        put_message("Error\nMap should contain at least one 'Coins'!\n", 2);
    validate_elements(game);
}
void check_map(t_game *game)
{
    check_elemnts(game);
}