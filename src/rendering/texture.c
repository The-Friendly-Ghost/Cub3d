/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 13:38:54 by mevan-de      #+#    #+#                 */
/*   Updated: 2023/01/18 14:14:05 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"
#include "cub3d_render.h"

#include <stdlib.h>
#include "cub3d_colors.h"

static int	calculate_texture_height_pixels(mlx_texture_t *texture, t_ray ray,
	int draw_height)
{
	int		height;
	float	height_divided;

	if (ray.wall_height > WINDOW_HEIGHT)
		draw_height += (ray.wall_height - WINDOW_HEIGHT) / 2;
	height_divided = texture->height / ray.wall_height;
	height = floor((height_divided * draw_height)) * texture->width;
	return (height);
}

static int	get_texture_pixel_color(mlx_texture_t *texture, t_ray ray,
	float current_height, int width_pixels)
{
	u_int8_t	*pixel;
	int			pixel_texture_location;

	pixel_texture_location = calculate_texture_height_pixels(texture, ray,
			current_height);
	pixel_texture_location += width_pixels;
	pixel_texture_location *= texture->bytes_per_pixel;
	pixel = &texture->pixels[pixel_texture_location];
	return (get_colour_from_pixel(pixel));
}

static int	calculate_texture_width_pixels(t_ray ray, int texture_width)
{
	float	width_pixels;

	if (ray.was_hit_horizontal)
		width_pixels = fmod(ray.horizontal_wall_hit.x, TILE_SIZE) / TILE_SIZE;
	else
		width_pixels = fmod(ray.vertical_wall_hit.y, TILE_SIZE) / TILE_SIZE;
	width_pixels *= texture_width;
	return (width_pixels);
}

void	draw_column(t_cub3d *cub3d, t_ray ray,
	struct mlx_texture *texture, int x)
{
	int		width;
	int		current_height;
	int		color;
	float	width_pixels;

	x = x * WALL_STRIP_WIDTH;
	width_pixels = calculate_texture_width_pixels(ray, texture->width);
	current_height = 0;
	while (ray.draw_start + current_height < ray.draw_end)
	{
		color = get_texture_pixel_color(texture, ray, current_height,
				width_pixels);
		width = 0;
		while (width < WALL_STRIP_WIDTH)
		{
			mlx_put_pixel(cub3d->images.walls, x + width,
				ray.draw_start + current_height, color);
			width++;
		}
		current_height++;
	}
}
