/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:25:27 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/06 00:41:56 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "./MLX42/include/MLX42/MLX42.h"

typedef struct s_position {
    int x_position;
    int y_position;
}   t_position;

typedef struct s_game {
    char    **map;
    char    **copy_map;
    mlx_t    *mlx;
    mlx_texture_t *ground_t;
    mlx_texture_t *wall_t;
    mlx_texture_t *player_t;
    mlx_texture_t *coins_t;
    mlx_texture_t *exit_t;
    mlx_image_t *ground;
    mlx_image_t *wall;
    mlx_image_t *player;
    mlx_image_t *coins;
    mlx_image_t *exit;
    int size_x;
    int size_y;
    int count_coins;
    int check_c;
    int count_exit;
    int check_e;
    int x;
    int y;
    t_position player_position;
    t_position exit_position;
}   t_game;

#include "./get_next_line/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_extension(char *arg, t_game *game);

void	put_error(char *s, int fd, t_game *game);

size_t ft_strlen(const char *s);

char    **get_map(char *file_name);

int count_element(char **map, char c);

void check_map(t_game *game);

void lenght_map(t_game *game);

void close_game(t_game *game);

void    print_map(t_game *game);

int move_processing(struct mlx_key_data keydata, void  *param);

void	ft_putnbr_fd(int n, int fd);

int    init_struct(t_game *game, char *filename);

void	ft_bzero(void *s, size_t n);

void flood_fill(t_game *game, int x, int y);

// void find_position(t_game *game, int i, int j);

#endif