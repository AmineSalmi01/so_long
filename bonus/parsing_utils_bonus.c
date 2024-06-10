/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:52:53 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/11 00:24:57 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	check_path(t_game *game)
{
	position_player(game);
	flood_fill(game, game->x_p, game->y_p);
	if (game->check_c != game->count_coins || game->check_e != game->count_exit)
		put_error("Error\nPath Invalid !\n", STDERR_FILENO, game);
}
