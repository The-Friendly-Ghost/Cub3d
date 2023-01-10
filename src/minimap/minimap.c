/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 16:29:23 by mevan-de      #+#    #+#                 */
/*   Updated: 2023/01/10 16:33:26 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d_structs.h"
#include "cub3d_colors.h"
#include "cub3d_render.h"
#include "cub3d_utils.h"

static void	draw_line(mlx_image_t *image, t_player player,
	float endX, float endY)
{
	float	length;
	float	step_x;
	float	step_y;
	t_rgb	red;

	red.blue = 0;
	red.red = 255;
	red.green = 0;
	length = get_dist_between_points((player.position.x * MINI_SCALE),
			(player.position.y * MINI_SCALE), endX, endY);
	step_x = (endX - MINI_SCALE * player.position.x) / length;
	step_y = (endY - MINI_SCALE * player.position.y) / length;
	while (length > 0)
	{
		mlx_put_pixel(image, endX, endY, convert_rgb_to_int(red));
		endY -= step_y;
		endX -= step_x;
		length--;
	}
}

static void	draw_square(mlx_image_t *image, float x, float y, float size)
{
	t_rgb	black;
	int		black_converted;
	float	x_start;
	float	y_start;

	black.red = 0;
	black.green = 0;
	black.blue = 0;
	black_converted = convert_rgb_to_int(black);
	x_start = x;
	y_start = y;
	while (y < y_start + size)
	{
		x = x_start;
		while (x < x_start + size)
		{
			mlx_put_pixel(image, x, y, black_converted);
			x++;
		}
		y++;
	}
}

void	draw_rays(t_player player, t_ray *rays, mlx_image_t *ray_image,
	float num_rays)
{
	int	i;

	i = 0;
	while (i < num_rays - 1)
	{
		if (rays[i].was_hit_horizontal)
			draw_line(ray_image, player, rays[i].horizontal_wall_hit.x
				* MINI_SCALE, rays[i].horizontal_wall_hit.y * MINI_SCALE);
		else if (rays[i].was_hit_vertical)
			draw_line(ray_image, player, rays[i].vertical_wall_hit.x
				* MINI_SCALE, rays[i].vertical_wall_hit.y * MINI_SCALE);
		i++;
	}
}

void	draw_mini_map(t_cub3d *cub3d, t_map map)
{
	int		x;
	int		y;
	float	step_x;
	float	step_y;

	cub3d->images.mini_map = alloc_check(mlx_new_image(cub3d->mlx,
				map.n_column * TILE_SIZE * MINI_SCALE + 1,
				map.n_row * TILE_SIZE * MINI_SCALE + 1));
	y = 0;
	step_y = 0;
	while (y < map.n_row)
	{
		x = 0;
		step_x = 0;
		while (x < map.n_column)
		{
			if (map.map[y][x] == '1')
				draw_square(cub3d->images.mini_map, step_x, step_y,
					(MINI_SCALE * TILE_SIZE));
			step_x += (MINI_SCALE * TILE_SIZE);
			x++;
		}
		step_y += (MINI_SCALE * TILE_SIZE);
		y++;
	}
	mlx_image_to_window(cub3d->mlx, cub3d->images.mini_map, 0, 0);
}
