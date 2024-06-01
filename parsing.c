/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:42:24 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/01 17:53:43 by asalmi           ###   ########.fr       */
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

void check_elemnts(t_game *game)
{
    if (count_elemnt(game, 'P') != 1)
        put_message("Error\nPlayer please !\n", 2);

}
void pars(t_game *game)
{
    check_elemnts(game);
}
