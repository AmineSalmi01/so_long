/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:22:53 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/01 17:54:17 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_struct(t_game *game, char *filename)
{
    game->map = get_map(filename);
}

int main(int ac, char **av)
{
    t_game *game = malloc(sizeof(t_game));

    if (ac != 2)
        put_message("Error\nProvide a map !", 2);
    check_extension(av[1]);
    init_struct(game, av[1]);
    pars(game);
    
    return 0;
}
