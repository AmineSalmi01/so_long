/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:52:56 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/10 22:48:20 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_game *game)
{
	int	i;

	if (game && game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
	if (game && game->copy_map)
	{
		i = 0;
		while (game->copy_map[i])
		{
			free(game->copy_map[i]);
			i++;
		}
		free(game->copy_map);
		game->copy_map = NULL;
	}
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

void	close_exit(t_game *game)
{
	if (game->exit_t)
		mlx_delete_texture(game->exit_t);
	if (game->exit)
		mlx_delete_image(game->mlx, game->exit);
	if (game->coins_tmp)
		mlx_delete_image(game->mlx, game->coins_tmp);
}

void	close_game(t_game *game)
{
	if (game->ground_t)
		mlx_delete_texture(game->ground_t);
	if (game->ground)
		mlx_delete_image(game->mlx, game->ground);
	if (game->wall_t)
		mlx_delete_texture(game->wall_t);
	if (game->wall)
		mlx_delete_image(game->mlx, game->wall);
	if (game->enemy_t)
		mlx_delete_texture(game->enemy_t);
	if (game->enemy)
		mlx_delete_image(game->mlx, game->enemy);
	if (game->coins_t)
		mlx_delete_texture(game->coins_t);
	if (game->coins)
		mlx_delete_image(game->mlx, game->coins);
	close_exit(game);
	close_player(game);
	close_coins_frame(game);
	mlx_close_window(game->mlx);
	free_map(game);
	if (game->err_exit)
		exit(1);
	exit(0);
}
