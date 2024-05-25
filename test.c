/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:26:20 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/25 22:46:51 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	// void 	*img;
// 	void 	*image;
// 	char	*relative_path = "./images/wall.xpm";
// 	int width;
// 	int height;
// 	// t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 2800, 1500, "Hello world!");
	
// 	// img = mlx_new_image(mlx, 640, 360);
// 	image = mlx_xpm_file_to_image(mlx,relative_path, &width, &height);
// 	int i = 0;
// 	int j = 0;
// 	while (i < 10)
// 	{
// 		j = 0;
// 		while (j < 10)
// 		{
			
// 			mlx_put_image_to_window(mlx, mlx_win,image, j, 0);
// 			j++;
// 		}
// 		i++;
// 	}
	
// 	mlx_loop(mlx);

// }
