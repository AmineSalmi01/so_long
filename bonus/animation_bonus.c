/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:22:48 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/11 14:44:31 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_coins_frame(t_game *game, int i)
{
	if (i <= 3)
		game->coins = game->coins_tmp;
	if (i > 3 && i <= 6)
		game->coins = game->frame.coins_frame2;
	else if (i > 6 && i <= 9)
		game->coins = game->frame.coins_frame3;
	else if (i > 9 && i <= 12)
		game->coins = game->frame.coins_frame4;
	else if (i > 12 && i <= 15)
		game->coins = game->frame.coins_frame5;
	else if (i > 15 && i <= 18)
		game->coins = game->frame.coins_frame6;
	else if (i > 18 && i <= 21)
		game->coins = game->frame.coins_frame7;
	else if (i > 21 && i <= 24)
		game->coins = game->frame.coins_frame8;
}

void	test_animation(void *param)
{
	t_game				*game;
	static int			i;
	struct mlx_key_data	keydata;

	keydata = (struct mlx_key_data){0};
	game = (t_game *)param;
	set_coins_frame(game, i);
	if (i == 24)
		i = 0;
	print_map(game, keydata);
	i++;
}
