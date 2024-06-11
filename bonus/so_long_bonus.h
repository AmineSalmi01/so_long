/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 00:19:55 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/11 14:34:15 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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

# define PATH_PLAYER_ENEMY "./images/enemy/enemy1.png"
# define PATH_GROUND "./images/other/ground.png"
# define PATH_WALL "./images/other/wall.png"
# define PATH_EXIT "./images/other/exit.png"

# define PATH_COINS_FRAME1 "./images/frame/coins_frame1.png"
# define PATH_COINS_FRAME2 "./images/frame/coins_frame2.png"
# define PATH_COINS_FRAME3 "./images/frame/coins_frame3.png"
# define PATH_COINS_FRAME4 "./images/frame/coins_frame4.png"
# define PATH_COINS_FRAME5 "./images/frame/coins_frame5.png"
# define PATH_COINS_FRAME6 "./images/frame/coins_frame6.png"
# define PATH_COINS_FRAME7 "./images/frame/coins_frame7.png"
# define PATH_COINS_FRAME8 "./images/frame/coins_frame8.png"

typedef struct s_frame
{
	mlx_texture_t	*coins_t_frame1;
	mlx_texture_t	*coins_t_frame2;
	mlx_texture_t	*coins_t_frame3;
	mlx_texture_t	*coins_t_frame4;
	mlx_texture_t	*coins_t_frame5;
	mlx_texture_t	*coins_t_frame6;
	mlx_texture_t	*coins_t_frame7;
	mlx_texture_t	*coins_t_frame8;
	mlx_image_t		*coins_frame1;
	mlx_image_t		*coins_frame2;
	mlx_image_t		*coins_frame3;
	mlx_image_t		*coins_frame4;
	mlx_image_t		*coins_frame5;
	mlx_image_t		*coins_frame6;
	mlx_image_t		*coins_frame7;
	mlx_image_t		*coins_frame8;
}					t_frame;

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
	mlx_texture_t	*player_t_right;
	mlx_texture_t	*player_t_up;
	mlx_texture_t	*player_t_down;
	mlx_texture_t	*player_t_left;
	mlx_texture_t	*coins_t;
	mlx_texture_t	*exit_t;
	mlx_texture_t	*enemy_t;
	mlx_image_t		*ground;
	mlx_image_t		*wall;
	mlx_image_t		*player_start;
	mlx_image_t		*player_right;
	mlx_image_t		*player_up;
	mlx_image_t		*player_down;
	mlx_image_t		*player_left;
	mlx_image_t		*coins;
	mlx_image_t		*coins_tmp;
	mlx_image_t		*exit;
	mlx_image_t		*enemy;
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
	char			*str_move;
	mlx_image_t		*move_img;
	t_position		player_position;
	t_position		exit_position;
	t_position		enemy_position;
	t_frame			frame;
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

void				load_frame(t_game *game);
void				load_frame2(t_game *game);
void				load_frame3(t_game *game);
void				load_frame4(t_game *game);

void				print_moves(t_game *game);
void				handle_direction(t_game *game, struct mlx_key_data keydata);
void				load_enemy(t_game *game);

char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);

void				close_player(t_game *game);
void				close_coins_frame(t_game *game);
void				test_animation(void *param);

void				exit_close(t_game *game);
void				enemy_close(t_game *game);

void				check_path(t_game *game);

void				print_player(t_game *game, struct mlx_key_data keydata,
						int i, int j);
void				print_enemy(t_game *game, int i, int j);
void				print_wall(t_game *game, int i, int j);
void				print_coins(t_game *game, int i, int j);
void				print_exit(t_game *game);

#endif