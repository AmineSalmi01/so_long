/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:22:40 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/10 02:16:08 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	count_line(int fd)
{
	int		counter;
	char	*line;

	counter = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		counter++;
	}
	return (counter);
}

char	**get_map(char *file_name)
{
	int		fd;
	char	*line;
	char	**map;
	int		size;
	int		i;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	size = count_line(fd);
	if (!size)
		return (NULL);
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
