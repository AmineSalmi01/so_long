/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:22:40 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/11 00:19:00 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	count_line(int fd)
{
	int		counter;
	char	*line;

	counter = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		counter++;
		free(line);
		line = get_next_line(fd);
	}
	return (counter);
}

char	**allocate_map(int size)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	return (map);
}

char	**read_map(int fd, int size)
{
	char	**map;
	char	*line;
	int		i;

	map = allocate_map(size);
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

char	**get_map(char *file_name)
{
	int		fd;
	int		size;
	char	**map;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	size = count_line(fd);
	if (!size)
		return (NULL);
	close(fd);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = read_map(fd, size);
	close(fd);
	return (map);
}
