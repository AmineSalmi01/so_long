/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:42:24 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/10 00:50:14 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P' && game->map[i][j] != '\n')
				put_error("Error\nInvalid map check your elements!\n",
					STDERR_FILENO, game);
			j++;
		}
		i++;
	}
}

void	check_lines(t_game *game)
{
	int	i;
	int	current;

	i = 0;
	while (game->map[i])
	{
		current = ft_strlen(game->map[i]);
		if (game->map[i + 1] && game->size_x != (current - 1))
			put_error("Error\nInvalid map check your lines!\n", STDERR_FILENO,
				game);
		else if (game->map[i + 1] == NULL && game->size_x != current)
			put_error("Error\nInvalid map check your lines!\n", STDERR_FILENO,
				game);
		i++;
	}
}

void	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			check_walls_inner(game, i, j);
			j++;
		}
		i++;
	}
}

void	check_elemnts(t_game *game)
{
	if (count_element(game->map, 'P') != 1)
		put_error("Error\nInvalid map check your 'Player'!\n", STDERR_FILENO,
			game);
	if (count_element(game->map, 'E') != 1)
		put_error("Error\nInvalid map check your 'Exit'!\n", STDERR_FILENO,
			game);
	if (!count_element(game->map, 'C'))
		put_error("Error\nInvalid map check your 'Coins'!\n", STDERR_FILENO,
			game);
	validate_elements(game);
}

void	check_map(t_game *game)
{
	check_lines(game);
	check_path(game);
	check_walls(game);
	check_elemnts(game);
}
