/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:22:53 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/09 23:31:42 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_struct(t_game *game, char *filename)
{
	game->map = get_map(filename);
	if (!game->map)
		return (0);
	game->copy_map = get_map(filename);
	if (!game->copy_map)
		return (0);
	lenght_map(game);
	game->check_c = 0;
	game->check_e = 0;
	game->count_exit = 0;
	game->err_exit = 0;
	game->move_counter = 0;
	game->count_coins = count_element(game->map, 'C');
	game->count_exit = count_element(game->copy_map, 'E');
	game->mlx = mlx_init(game->size_x * 40, game->size_y * 40, "so_long",
			false);
	return (1);
}

void	set_game(t_game *game)
{
	game->player_t_start = mlx_load_png(PATH_PLAYER_START);
	if (!game->player_t_start)
	{
		game->err_exit++;
		close_game(game);
	}
	game->player_start = mlx_texture_to_image(game->mlx, game->player_t_start);
	if (!game->player_start)
	{
		game->err_exit++;
		close_game(game);
	}
	load_gound_and_wall(game);
	load_player(game);
	load_coins_and_exit(game);
}

int	main(int ac, char **av)
{
	t_game				game;
	struct mlx_key_data	keydata;

	ft_bzero(&game, sizeof(t_game));
	keydata = (struct mlx_key_data){0};
	if (ac != 2)
		put_error("Error\nProvide a map !", STDERR_FILENO, &game);
	check_extension(av[1], &game);
	if (!init_struct(&game, av[1]))
		put_error("Error\nEmpty map !", STDERR_FILENO, &game);
	check_map(&game);
	set_game(&game);
	print_map(&game, keydata);
	mlx_key_hook(game.mlx, (mlx_keyfunc)move_processing, &game);
	mlx_close_hook(game.mlx, win_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
