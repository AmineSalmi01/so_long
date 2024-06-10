/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:49:55 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/10 02:37:03 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(t_game *game)
{
	position_player(game);
	flood_fill(game, game->x_p, game->y_p);
	if (game->check_c != game->count_coins || game->check_e != game->count_exit)
		put_error("Error\nPath Invalid !\n", STDERR_FILENO, game);
}

void	check_extension(char *arg, t_game *game)
{
	char	*str;
	int		len_arg;
	int		len_str;
	int		fd;

	str = ".ber";
	len_arg = ft_strlen(arg) - 1;
	len_str = ft_strlen(str) - 1;
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		put_error("Error\nCheck your file !\n", STDERR_FILENO, game);
	if (len_arg <= len_str)
		put_error("Error\nCheck your file !\n", STDERR_FILENO, game);
	while (len_arg > 0 && len_str > 0)
	{
		if (arg[len_arg--] != str[len_str--])
			put_error("Error\nCheck your file !\n", STDERR_FILENO, game);
	}
	close(fd);
}

void	check_walls_inner(t_game *game, int i, int j)
{
	if (i == 0 && game->map[i][j + 1] != '\0' && game->map[i][j] != '1')
		put_error("Error\nInvalid map check your walls!\n", STDERR_FILENO, game);
	else if (j == 0 && game->map[i][j] != '1')
		put_error("Error\nInvalid map check your walls!\n", STDERR_FILENO, game);
	if (j > 0 && game->map[i][j - 1] != '1' && game->map[i][j + 1] == '\0')
		put_error("Error\nInvalid map check your walls!\n", STDERR_FILENO, game);
	if (game->map[i + 1] == NULL && game->map[i][j] != '1')
		put_error("Error\nInvalid map check your walls!\n", STDERR_FILENO, game);
}
