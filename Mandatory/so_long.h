/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:25:27 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/07 01:23:37 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define PATH_PLAYER_START "./images/player/player_start.png"
# define PATH_PLAYER_RIGHT "./images/player/player_right.png"
# define PATH_PLAYER_LEFT "./images/player/player_left.png"
# define PATH_PLAYER_UP "./images/player/player_up.png"
# define PATH_PLAYER_DOWN "./images/player/player_down.png"

# define PATH_GROUND "./images/other/ground.png"
# define PATH_WALL "./images/other/wall.png"
# define PATH_COINS "./images/coins/coins1.png"
# define PATH_EXIT "./images/other/exit.png"

typedef struct s_position
{
	int				x_position;
	int				y_position;
}					t_position;

typedef struct s_game
{
	char			**map;
	char			**copy_map;
	mlx_t			*mlx;
	mlx_texture_t	*ground_t;
	mlx_texture_t	*wall_t;
	mlx_texture_t	*player_t_start;
	mlx_texture_t	*player_t_Right;
	mlx_texture_t	*player_t_up;
	mlx_texture_t	*player_t_down;
	mlx_texture_t	*player_t_left;
	mlx_texture_t	*coins_t;
	mlx_texture_t	*exit_t;
	mlx_image_t		*ground;
	mlx_image_t		*wall;
	mlx_image_t		*player_start;
	mlx_image_t		*player_right;
	mlx_image_t		*player_up;
	mlx_image_t		*player_down;
	mlx_image_t		*player_left;
	mlx_image_t		*coins;
	mlx_image_t		*exit;
	int				size_x;
	int				size_y;
	int				count_coins;
	int				count_exit;
	int				check_c;
	int				check_e;
	int				x_p;
	int				y_p;
	int				err_exit;
	int				has_moved;
	int				move_counter;
	t_position		player_position;
	t_position		exit_position;
}					t_game;

void				check_extension(char *arg, t_game *game);

void				put_error(char *s, int fd, t_game *game);

size_t				ft_strlen(const char *s);

char				**get_map(char *file_name);

int					count_element(char **map, char c);

void				check_map(t_game *game);

void				lenght_map(t_game *game);

void				close_game(t_game *game);

void				print_map(t_game *game, struct mlx_key_data keydata);

int					move_processing(struct mlx_key_data keydata, void *param);

void				ft_putnbr_fd(int n, int fd);

int					init_struct(t_game *game, char *filename);

void				ft_bzero(void *s, size_t n);

void				flood_fill(t_game *game, int x, int y);

void				position_player(t_game *game);

void				win_close(void *param);

void				load_gound_and_wall(t_game *game);
void				load_coins_and_exit(t_game *game);
void				load_player(t_game *game);

void				print_moves(t_game *game);

void				check_walls_inner(t_game *game, int i, int j);

void				check_path(t_game *game);
void				handle_direction(t_game *game, struct mlx_key_data keydata);

#endif