/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:22:53 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/04 21:11:28 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_struct(t_game *game, char *filename)
{
    game->map = get_map(filename);
    lenght_map(game);
    game->exit_error = 0;
    game->mlx = mlx_init(game->size_x * 40, game->size_y * 40, "so_long", false);
    game->count_coins = count_element(game->map, 'C');
}

void set_game(t_game *game)
{
    game->ground_t = mlx_load_png("./images/other/ground.png");
    if (!game->ground_t)
        close_game(game);
    game->ground = mlx_texture_to_image(game->mlx, game->ground_t);
    if (!game->ground_t)
        close_game(game);
    game->wall_t = mlx_load_png("./images/other/wall.png");
    if (!game->wall_t)
        close_game(game);
    game->wall = mlx_texture_to_image(game->mlx, game->wall_t);
    if (!game->wall)
        close_game(game);
    game->player_t = mlx_load_png("./images/player/player.png");
    if (!game->player_t)
        close_game(game);
    game->player = mlx_texture_to_image(game->mlx, game->player_t);
    if (!game->player)
        close_game(game);
    game->coins_t = mlx_load_png("./images/coins/coins1.png");
    if (!game->coins_t)
        close_game(game);
    game->coins = mlx_texture_to_image(game->mlx, game->coins_t);
    if (!game->coins)
        close_game(game);
    game->exit_t = mlx_load_png("./images/other/exit.png");
    if (!game->exit_t)
        close_game(game);
    game->exit = mlx_texture_to_image(game->mlx, game->exit_t);
    if (!game->exit)
        close_game(game);
}

void leaks()
{
    system("leaks so_Long");
}
int main(int ac, char **av)
{
    atexit(leaks);
    t_game *game = malloc(sizeof(t_game));

    if (ac != 2)
        put_message("Error\nProvide a map !", 2, game);
    check_extension(av[1], game);
    init_struct(game, av[1]);
    check_map(game);
    set_game(game);
    print_map(game);
    mlx_key_hook(game->mlx, (mlx_keyfunc)move_processing, game);
    mlx_loop(game->mlx);
    return 0;
}
