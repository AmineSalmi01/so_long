/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:52:56 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/03 23:22:24 by asalmi           ###   ########.fr       */
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
	if (game->map)
		free_map(game);
}
