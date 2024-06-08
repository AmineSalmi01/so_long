/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:43:36 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/07 15:43:19 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int count_element(char **map, char c)
{
    int i;
    int j;
    int counter;

    i = 0;
    counter = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == c)
                counter++;
            j++;
        }
        i++;
    }
    return (counter);
}

void    lenght_map(t_game *game)
{
    game->size_x = 0;
    game->size_y = 0;
    while (game->map[game->size_y])
    {
        if (game->size_y == 0)
        {
            while (game->map[game->size_y][(game->size_x) + 1])
                (game->size_x)++;
        }
        (game->size_y)++;
    }
    if (game->size_x < 1 || game->size_y < 1)
        put_error("Error\nMap dimensions are too small!\n", STDERR_FILENO, game);
    if (game->size_x > 64 || game->size_y > 34)
        put_error("Error\nMap dimensions are too large!\n", STDERR_FILENO, game);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n > 2147483647 || n < -2147483648)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}
	else
	{
		ft_putchar_fd(n + 48, fd);
	}
}
