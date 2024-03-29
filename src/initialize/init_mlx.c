/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 11:21:08 by mevan-de      #+#    #+#                 */
/*   Updated: 2023/01/19 14:10:30 by mevan-de      ########   odam.nl         */
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

static mlx_image_t	*create_background_image(mlx_t *mlx, t_rgb color)
{
	mlx_image_t	*image;

	image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT / 2);
	if (!image)
		exit_error("Failed to create background image", 1);
	fill_image(image, color);
	return (image);
}

static void	init_main_images(mlx_t *mlx, t_images *images, t_rgb floor,
	t_rgb ceiling)
{
	images->ceiling = create_background_image(mlx, ceiling);
	images->floor = create_background_image(mlx, floor);
	mlx_image_to_window(mlx, images->ceiling, 0, 0);
	mlx_image_to_window(mlx, images->floor, 0, WINDOW_HEIGHT / 2);
	images->walls = alloc_check(
			mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT));
	images->rays = NULL;
}

void	delete_textures(t_map *map_data)
{
	if (map_data->north_wall)
		mlx_delete_texture(map_data->north_wall);
	if (map_data->south_wall)
		mlx_delete_texture(map_data->south_wall);
	if (map_data->east_wall)
		mlx_delete_texture(map_data->east_wall);
	if (map_data->west_wall)
		mlx_delete_texture(map_data->west_wall);
}

void	start_game(t_cub3d *cub3d_data)
{
	cub3d_data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D", true);
	if (!cub3d_data->mlx)
		exit_error("Failed to init MLX", 1);
	init_main_images(cub3d_data->mlx, &cub3d_data->images,
		*(cub3d_data->map_data.floor), *(cub3d_data->map_data.ceiling));
	draw_mini_map(cub3d_data, cub3d_data->map_data, get_scale(cub3d_data));
	mlx_loop_hook(cub3d_data->mlx, key_loop, cub3d_data);
	mlx_loop_hook(cub3d_data->mlx, update_loop, cub3d_data);
	mlx_loop(cub3d_data->mlx);
	if (cub3d_data->rays)
		free (cub3d_data->rays);
	delete_textures(&cub3d_data->map_data);
	mlx_terminate(cub3d_data->mlx);
}
