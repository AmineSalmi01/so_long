/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:22:40 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/07 15:43:19 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t  count_line(int fd)
{
    int counter;
    char *line;

    counter = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        free(line);
        counter++;
    }
    return (counter);
}

char    **get_map(char *file_name)
{
    int fd;
    char *line;
    char **map;
    int size;
    int i;

    fd = open(file_name, O_RDONLY);
    if (fd < 0)
        return (NULL);
    size = count_line(fd);
    if(!size)
        return NULL;
    close(fd);
    map = (char **)malloc(sizeof(char *) * (size + 1));
    if (!map)
        return (NULL);
    fd = open(file_name, O_RDONLY);
    if (fd < 0)
    {
        free(map);
        return (NULL);
    }
    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        map[i] = line;
        i++;
    }
    map[i] = NULL;
    close(fd);
    return (map);
}
// int main()
// {
//     atexit(ll);
//     char **s = get_map("amine.txt");
//     for (int i = 0; s[i] != NULL; i++)
//         printf("%s", s[i]);
//     printf("\nPress any key to exit...\n");
//     getchar();
//     return 0;
// }