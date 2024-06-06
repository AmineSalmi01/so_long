/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:22:53 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/06 13:08:00 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void find_position(t_game *game, int i, int j)
// {
//     game->player_position.x_position = j;
//     game->player_position.y_position = i;
//     printf("x = %d\n", game->player_position.x_position);
//     printf("y = %d\n", game->player_position.y_position);
// }

int    init_struct(t_game *game, char *filename)
{
    game->map = get_map(filename);  
    if(!game->map)
        return 0;
    game->copy_map = get_map(filename);
    if (!game->copy_map)
        return 0;
    lenght_map(game);
    game->check_c = 0;
    game->check_e = 0;
    game->count_exit = 0;
    game->err_exit = 0;
    game->count_coins = count_element(game->map, 'C');
    game->count_exit = count_element(game->copy_map, 'E');
    game->mlx = mlx_init(game->size_x * 40, game->size_y * 40, "so_long", false);
    return 1;
}

void set_game(t_game *game)
{
    game->ground_t = mlx_load_png("./images/other/ground.png");
    if (!game->ground_t)
    {
        game->err_exit++;
        close_game(game);
    }
    game->ground = mlx_texture_to_image(game->mlx, game->ground_t);
    if (!game->ground_t)
    {
        game->err_exit++;
        close_game(game);
    }
    game->wall_t = mlx_load_png("./images/other/wall.png");
    if (!game->wall_t)
    {
        game->err_exit++;
        close_game(game);
    }
    game->wall = mlx_texture_to_image(game->mlx, game->wall_t);
    if (!game->wall)
    {
        game->err_exit++;
        close_game(game);
    }
    game->player_t = mlx_load_png("./images/player/player.png");
    if (!game->player_t)
    {
        game->err_exit++;
        close_game(game);
    }
    game->player = mlx_texture_to_image(game->mlx, game->player_t);
    if (!game->player)
    {
        game->err_exit++;
        close_game(game);
    }
    game->coins_t = mlx_load_png("./images/coins/coins1.png");
    if (!game->coins_t)
    {
        game->err_exit++;
        close_game(game);
    }
    game->coins = mlx_texture_to_image(game->mlx, game->coins_t);
    if (!game->coins)
    {
        game->err_exit++;
        close_game(game);
    }
    game->exit_t = mlx_load_png("./images/other/exit.png");
    if (!game->exit_t)
    {
        game->err_exit++;
        close_game(game);
    }
    game->exit = mlx_texture_to_image(game->mlx, game->exit_t);
    if (!game->exit)
    {
        game->err_exit++;
        close_game(game);
    }
}

void leaks()
{
    system("leaks so_Long");
}
int main(int ac, char **av)
{
    atexit(leaks);
    t_game game;

    ft_bzero(&game, sizeof(t_game));
    if (ac != 2)
        put_error("Error\nProvide a map !", STDERR_FILENO, &game);
    check_extension(av[1], &game);
    if(!init_struct(&game, av[1]))
        put_error("Error\nEmpty map !", STDERR_FILENO, &game);
    check_map(&game);
    set_game(&game);
    print_map(&game);
    mlx_key_hook(game.mlx, (mlx_keyfunc)move_processing, &game);
    mlx_close_hook(game.mlx, win_close, &game);
    mlx_loop(game.mlx);
    return 0;
}
