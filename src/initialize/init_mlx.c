/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:21:08 by mevan-de          #+#    #+#             */
/*   Updated: 2022/12/19 12:45:19 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_utils.h"
#include "cub3d_render.h"
#include "cub3d_structs.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include "cub3d_colors.h"
#include "cub3d_movement.h"

void	fill_image(mlx_image_t *img, t_rgb rgb_color)
{
	int	color;
	int	x;
	int	y;

	color = convert_rgb_to_int(rgb_color);
	y = 0;
	while (y < (int)img->height)
	{
		x = 0;
		while (x < (int)img->width)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

static mlx_image_t	*create_background_image(mlx_t *mlx, t_rgb color, int posx, int posy)
{
	mlx_image_t	*image;
	image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT / 2);
	if (!image)
		exit_error("Failed to create background image\n", 1);
	fill_image(image, color);
	mlx_image_to_window(mlx, image, posx, posy);
	return (image);
}

static void init_main_images(mlx_t *mlx, t_images *images, t_rgb floor,
	t_rgb ceiling)
{
	images->ceiling = create_background_image(mlx, ceiling, 0, 0);
	images->floor = create_background_image(mlx, floor, 0, WINDOW_HEIGHT / 2);
	printf("background created!\n");
	
}

void	init_mlx(t_cub3d *cub3d_data)
{
	cub3d_data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D", true);
	if (!cub3d_data->mlx)
		exit_error("Failed to init MLX\n", 1);
	init_main_images(cub3d_data->mlx, &cub3d_data->images,
				*(cub3d_data->map_data.floor), *(cub3d_data->map_data.ceiling));
	mlx_key_hook(cub3d_data->mlx, key_hook, cub3d_data);
	mlx_loop_hook(cub3d_data->mlx, update_loop, cub3d_data);
	mlx_loop(cub3d_data->mlx);
	mlx_terminate(cub3d_data->mlx);
}
