/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_loop.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 12:02:12 by mevan-de      #+#    #+#                 */
/*   Updated: 2023/01/16 13:28:50 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_utils.h"
#include "cub3d_render.h"
#include "cub3d_structs.h"
#include "cub3d_movement.h"

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include "cub3d_colors.h"

static void	set_draw_values(t_ray *rays, float distance_to_plane,
	float num_rays)
{
	int		column_id;
	t_ray	*ray;

	column_id = 0;
	while (column_id < num_rays)
	{
		ray = &rays[column_id];
		ray->wall_height = ((float)TILE_SIZE / ray->distance)
			* distance_to_plane;
		ray->draw_start = (WINDOW_HEIGHT / 2) - (ray->wall_height / 2);
		ray->draw_end = ray->draw_start + ray->wall_height;
		if (ray->wall_height > WINDOW_HEIGHT)
		{
			ray->draw_start = 0;
			ray->draw_end = WINDOW_HEIGHT;
		}
		column_id++;
	}
}

//not working correctly?
int	get_texture_color(mlx_texture_t *texture, t_ray ray,
	int current_height, int width_scalar)
{
	float		height_scalar;
	u_int8_t	*pixel;
	int			pixel_texture_location;

	height_scalar =  (current_height / ray.wall_height);
//	printf("height_scalar = %f\n", height_scalar);
	pixel_texture_location = (height_scalar * texture->height) * texture->width
		+ (width_scalar * texture->width);
	pixel = &texture->pixels[(pixel_texture_location * 4)];
	return (get_colour_from_pixel(pixel));
}

float	calculate_texture_width_scalar(t_ray ray)
{
	float	width_scalar;

	if (ray.was_hit_horizontal)
		width_scalar = fmod(ray.horizontal_wall_hit.x, TILE_SIZE) / TILE_SIZE;
	else
		width_scalar = TILE_SIZE / ray.vertical_wall_hit.y;
	printf("width scalar = %f\n", width_scalar);
	return (width_scalar);
}

//TODO: get the correct color from the texture :)
static void	draw_texture(t_cub3d *cub3d, t_ray ray,
	struct mlx_texture *texture, int x)
{
	int		width;
	int		current_height;
	int		color;
	float	width_scalar;

	current_height = 0;
	x = x * WALL_STRIP_WIDTH;
	width_scalar = calculate_texture_width_scalar(ray);
	while (ray.draw_start + current_height < ray.draw_end)
	{
		color = get_texture_color(texture, ray, current_height, width_scalar);
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

static void	draw_walls(t_cub3d *cub3d, t_ray *rays)
{
	int	i;

	set_draw_values(rays, cub3d->distance_to_plane, cub3d->num_rays);
	i = 0;
	while (i < cub3d->num_rays)
	{
		if (rays[i].hit_wall_direction == NORTH)
			draw_texture(cub3d, rays[i], cub3d->map_data.north_wall, i);
		else if (rays[i].hit_wall_direction == SOUTH)
			draw_texture(cub3d, rays[i], cub3d->map_data.south_wall, i);
		else if (rays[i].hit_wall_direction == EAST)
			draw_texture(cub3d, rays[i], cub3d->map_data.east_wall, i);
		else if (rays[i].hit_wall_direction == WEST)
			draw_texture(cub3d, rays[i], cub3d->map_data.west_wall, i);
		i++;
	}
}

void	render(t_cub3d *cub3d_data)
{
	t_ray	*rays;
	bool	should_draw_rays;

	should_draw_rays = true;
	rays = cast_all_rays(cub3d_data);
	if (cub3d_data->images.walls)
	{
		mlx_delete_image(cub3d_data->mlx, cub3d_data->images.walls);
		cub3d_data->images.walls = alloc_check(mlx_new_image(cub3d_data->mlx,
					WINDOW_WIDTH, WINDOW_HEIGHT));
	}
	draw_walls(cub3d_data, rays);
	mlx_image_to_window(cub3d_data->mlx, cub3d_data->images.walls, 0, 0);
	mlx_set_instance_depth(cub3d_data->images.walls->instances, 3);
	mlx_set_instance_depth(cub3d_data->images.mini_map->instances, 4);
	if (should_draw_rays)
		draw_rays(cub3d_data->player_data, rays, cub3d_data,
			cub3d_data->num_rays);
	free(rays);
}

void	update_loop(void *data)
{
	t_cub3d	*cub3d_data;

	cub3d_data = data;
	turn_player(&cub3d_data->player_data);
	try_move_player(&cub3d_data->map_data, &cub3d_data->player_data);
	try_strafe_player(&cub3d_data->map_data, &cub3d_data->player_data);
	render(cub3d_data);
}
