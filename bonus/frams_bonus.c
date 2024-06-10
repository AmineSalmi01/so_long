/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frams_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:53:12 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/10 14:52:15 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void load_frame1(t_game *game)
{
    game->frame.coins_t_frame1 = mlx_load_png(PATH_COINS_FRAME1);
    if (!game->frame.coins_t_frame1)
    {
        game->err_exit++;
        close_game(game);
    }
    game->frame.coins_frame1 = mlx_texture_to_image(game->mlx, game->frame.coins_t_frame1);
    if (!game->frame.coins_frame1)
    {
        game->err_exit++;
        close_game(game);
    }
    game->frame.coins_t_frame2 = mlx_load_png(PATH_COINS_FRAME2);
    if (!game->frame.coins_t_frame2)
    {
        game->err_exit++;
        close_game(game);
    }
    game->frame.coins_frame2 = mlx_texture_to_image(game->mlx, game->frame.coins_t_frame2);
    if (!game->frame.coins_frame2)
    {
        game->err_exit++;
        close_game(game);
    }
}

void load_frame2(t_game *game)
{
    game->frame.coins_t_frame3 = mlx_load_png(PATH_COINS_FRAME3);
    if (!game->frame.coins_t_frame3)
    {
        game->err_exit++;
        close_game(game);
    }
    game->frame.coins_frame3 = mlx_texture_to_image(game->mlx, game->frame.coins_t_frame3);
    if (!game->frame.coins_frame3)
    {
        game->err_exit++;
        close_game(game);
    }
    game->frame.coins_t_frame4 = mlx_load_png(PATH_COINS_FRAME4);
    if (!game->frame.coins_t_frame4)
    {
        game->err_exit++;
        close_game(game);
    }
    game->frame.coins_frame4 = mlx_texture_to_image(game->mlx, game->frame.coins_t_frame4);
    if (!game->frame.coins_frame4)
    {
        game->err_exit++;
        close_game(game);
    }
    
}

void load_frame3(t_game *game)
{
    game->frame.coins_t_frame5 = mlx_load_png(PATH_COINS_FRAME5);
    if (!game->frame.coins_t_frame5)
    {
        game->err_exit++;
        close_game(game);
    }
    game->frame.coins_frame5 = mlx_texture_to_image(game->mlx, game->frame.coins_t_frame5);
    if (!game->frame.coins_frame5)
    {
        game->err_exit++;
        close_game(game);
    }
    game->frame.coins_t_frame6 = mlx_load_png(PATH_COINS_FRAME6);
    if (!game->frame.coins_t_frame6)
    {
        game->err_exit++;
        close_game(game);
    }
    game->frame.coins_frame6 = mlx_texture_to_image(game->mlx, game->frame.coins_t_frame6);
    if (!game->frame.coins_frame6)
    {
        game->err_exit++;
        close_game(game);
    }
}

void load_frame4(t_game *game)
{
    game->frame.coins_t_frame7 = mlx_load_png(PATH_COINS_FRAME7);
    if (!game->frame.coins_t_frame7)
    {
        game->err_exit++;
        close_game(game);
    }
    game->frame.coins_frame7 = mlx_texture_to_image(game->mlx, game->frame.coins_t_frame7);
    if (!game->frame.coins_frame7)
    {
        game->err_exit++;
        close_game(game);
    }
    game->frame.coins_t_frame8 = mlx_load_png(PATH_COINS_FRAME8);
    if (!game->frame.coins_t_frame8)
    {
        game->err_exit++;
        close_game(game);
    }
    game->frame.coins_frame8 = mlx_texture_to_image(game->mlx, game->frame.coins_t_frame8);
    if (!game->frame.coins_frame8)
    {
        game->err_exit++;
        close_game(game);
    }
}
