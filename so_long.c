/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:36:21 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/26 22:37:43 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_line(int fd)
{
    int count;
    char *line;

    count = 0;
    while((line = get_next_line(fd)) != NULL)
    {
        free(line);
        count++;
    }
    return (count);
}

char    **get_map()
{
    int fd;
    int i;
    char **map;
    char *line;
    int size;

    fd = open("map.txt", O_RDONLY);
    if (fd < 0)
        return (NULL);
    size = count_line(fd);
    close(fd);
    map = (char **)malloc(sizeof(char *) * (size + 1));
    if (!map)
        return (NULL);
    fd = open("map.txt", O_RDONLY);
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

int main()
{
    void    *mlx;
    void    *win;
    void    *img;
    void    *image;
	int width;
	int height;
    char **map;
    int i, j;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 500, 300, "so_long");
    img = mlx_new_image(mlx, 600, 360);
    image = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &width, &height);

    i = 0;
    map = get_map();
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1')
                mlx_put_image_to_window(mlx, win,image, i * 140, j * 140);
            j++;
        }
        i++;
    }

    mlx_loop(mlx);
}
