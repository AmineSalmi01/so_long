/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:52:56 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/05 21:23:09 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(t_game *game)
{
	int i;

	if (game && game->map == NULL)
		return ;
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	if(game->map)
		free(game->map);
	game->map = NULL;
}

void	put_error(char *s, int fd, t_game *game)
{
	(void)game;
	if (!s)
		return ;
	if (fd < 0)
		return ;
	if (*s)
		write(fd, s, ft_strlen(s));
	free_map(game);
    exit(1);
}

void close_game(t_game *game)
{
	if (game->ground_t)
		mlx_delete_texture(game->ground_t);
	if (game->ground)
		mlx_delete_image(game->mlx, game->ground);
	if (game->wall_t)
		mlx_delete_texture(game->wall_t);
	if (game->wall)
		mlx_delete_image(game->mlx, game->wall);
	if (game->player_t)
		mlx_delete_texture(game->player_t);
	if (game->player)
		mlx_delete_image(game->mlx, game->player);
	if (game->coins_t)
		mlx_delete_texture(game->coins_t);
	if (game->coins)
		mlx_delete_image(game->mlx, game->coins);
	if (game->exit_t)
		mlx_delete_texture(game->exit_t);
	if (game->exit)
		mlx_delete_image(game->mlx, game->exit);
	mlx_close_window(game->mlx);
	free_map(game);
	exit(0);
}
