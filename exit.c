/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:52:56 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/02 13:55:12 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_message(char *s, int fd, t_game *game)
{
	if (!s)
		return ;
	if (fd < 0)
		return ;
	if (*s)
		write(fd, s, ft_strlen(s));
	free(game);
    exit(1);
}
void free_map(t_game *game)
{
	int i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}
