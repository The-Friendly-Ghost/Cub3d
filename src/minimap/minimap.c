/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 16:29:23 by mevan-de      #+#    #+#                 */
/*   Updated: 2023/01/18 15:26:44 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d_structs.h"
#include "cub3d_colors.h"
#include "cub3d_render.h"
#include "cub3d_utils.h"

static void	draw_line(mlx_image_t *image, t_cub3d *cub3d,
	float endX, float endY)
{
	float	length;
	float	step_x;
	float	step_y;
	float	scale;

	scale = get_scale(cub3d);
	length = get_dist_between_points((cub3d->player_data.position.x * scale),
			(cub3d->player_data.position.y * scale), endX, endY);
	step_x = (endX - scale * cub3d->player_data.position.x) / length;
	step_y = (endY - scale * cub3d->player_data.position.y) / length;
	while (length > 0)
	{
		mlx_put_pixel(image, endX, endY, RED);
		endY -= step_y;
		endX -= step_x;
		length--;
	}
}

static void	draw_square(t_cub3d *cub3d, float x, float y, long color)
{
	float	x_start;
	float	y_start;
	float	scale;

	x_start = x;
	y_start = y;
	scale = get_scale(cub3d);
	while (y < y_start + (scale * TILE_SIZE))
	{
		x = x_start;
		while (x < x_start + (scale * TILE_SIZE))
		{
			mlx_put_pixel(cub3d->images.mini_map, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_rays(t_ray *rays, t_cub3d *cub3d,
	float num_rays)
{
	int		i;
	float	scale;

	i = 0;
	scale = get_scale(cub3d);
	if (cub3d->images.rays)
		mlx_delete_image(cub3d->mlx, cub3d->images.rays);
	cub3d->images.rays = alloc_check(mlx_new_image(cub3d->mlx,
				cub3d->map_data.n_column * TILE_SIZE * scale,
				cub3d->map_data.n_row * TILE_SIZE * scale));
	while (i < num_rays - 1)
	{
		if (rays[i].was_hit_horizontal)
			draw_line(cub3d->images.rays, cub3d,
				rays[i].horizontal_wall_hit.x
				* scale, rays[i].horizontal_wall_hit.y * scale);
		else if (rays[i].was_hit_vertical)
			draw_line(cub3d->images.rays, cub3d,
				rays[i].vertical_wall_hit.x
				* scale, rays[i].vertical_wall_hit.y * scale);
		i++;
	}
	mlx_image_to_window(cub3d->mlx, cub3d->images.rays, 0, 0);
	mlx_set_instance_depth(cub3d->images.rays->instances, 5);
}

void	create_map_image(t_cub3d *cub3d, t_map map)
{
	float	scale;

	scale = get_scale(cub3d);
	cub3d->images.mini_map = alloc_check(mlx_new_image(cub3d->mlx,
				map.n_column * TILE_SIZE * scale + 1,
				map.n_row * TILE_SIZE * scale + 1));
}

void	draw_mini_map(t_cub3d *cub3d, t_map map, float scale)
{
	int		x;
	int		y;
	float	step_x;
	float	step_y;

	create_map_image(cub3d, map);
	y = 0;
	step_y = 0;
	while (y < map.n_row)
	{
		x = 0;
		step_x = 0;
		while (x < map.n_column)
		{
			if (map.map[y][x] == '1')
				draw_square(cub3d, step_x, step_y, BLACK);
			else if (map.map[y][x] != ' ')
				draw_square(cub3d, step_x, step_y, WHITE);
			step_x += (scale * TILE_SIZE);
			x++;
		}
		step_y += (scale * TILE_SIZE);
		y++;
	}
	mlx_image_to_window(cub3d->mlx, cub3d->images.mini_map, 0, 0);
}
