/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:42:24 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/02 13:31:27 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_extension(char *arg, t_game *game)
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
        put_message("Error\nCheck your file !\n", 2, game);
    if (len_arg <= len_str)
        put_message("Error\nCheck your file !\n", 2, game);
    while (len_arg > 0 && len_str > 0)
    {
        if (arg[len_arg--] != str[len_str--])
            put_message("Error\nCheck your file !\n", 2, game);
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
                put_message("Error\nInvalid map check your elements!\n", 2, game);
            j++;
        }
        i++;
    }
}

void check_lines(t_game *game)
{
    int i;
    int current;

    i = 0;
    while (game->map[i])
    {
        current = ft_strlen(game->map[i]);
        if (game->map[i + 1] && game->size_x != (current - 1))
            put_message("Error\nInvalid map check your lines!\n", 2, game);
        else if (game->map[i + 1 ] == NULL && game->size_x != current)
            put_message("Error\nInvalid map check your lines!\n", 2, game);
        i++;
    }
}

void check_walls(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (i == 0 && game->map[i][j + 1] != '\0' && game->map[i][j] != '1')
                put_message("Error\nInvalid map check your walls!\n", 2, game);
            else if (j == 0 && game->map[i][j] != '1')
                put_message("Error\nInvalid map check your walls!\n", 2, game);
            if (j > 0 && game->map[i][j - 1] != '1' && game->map[i][j + 1] == '\0')
                put_message("Error\nInvalid map check your walls!\n", 2, game);
            if (game->map[i + 1] == NULL && game->map[i][j] != '1')
                put_message("Error\nInvalid map check your walls!\n", 2, game);
            j++;
        }
        i++;
    }
}

void check_elemnts(t_game *game)
{
    if (count_element(game->map, 'P') != 1)
        put_message("Error\nInvalid map check your 'Player'!\n", 2, game);
    if (count_element(game->map, 'E') != 1)
        put_message("Error\nInvalid map check your 'Exit'!\n", 2, game);
    if (!count_element(game->map, 'C'))
        put_message("Error\nInvalid map check your 'Coins'!\n", 2, game);
    validate_elements(game);
}
void check_map(t_game *game)
{
    check_lines(game);
    check_walls(game);
    check_elemnts(game);
}
