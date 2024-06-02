/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:25:27 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/02 17:18:56 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct s_game {
    char    **map;
    int size_x;
    int size_y;
}   t_game;

#include "./get_next_line/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_extension(char *arg, t_game *game);

void	put_message(char *s, int fd, t_game *game);

size_t ft_strlen(const char *s);

char    **get_map(char *file_name);

int count_element(char **map, char c);

void check_map(t_game *game);

void lenght_map(t_game *game);

#endif