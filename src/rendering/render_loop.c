/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:02:12 by mevan-de          #+#    #+#             */
/*   Updated: 2023/01/02 14:12:19 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_utils.h"
#include "cub3d_render.h"
#include "cub3d_structs.h"

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static void set_draw_values(t_ray *rays)
{
	int		column_id;
	float	distanceToPlane;
	t_ray	ray;

	column_id = 0;
	distanceToPlane = (WINDOW_WIDTH / 2) / tan(FOV / 2);
	while (column_id < NUM_RAYS)
	{
		ray = rays[column_id];
		ray.wall_height = (TILE_SIZE / ray.distance) * distanceToPlane;
		ray.draw_start = (WINDOW_HEIGHT / 2) - (ray.wall_height / 2);
		ray.draw_end = ray.draw_start + ray.wall_height;
		if (ray.draw_end > WINDOW_HEIGHT)
		{
			ray.draw_start = 0;
			ray.draw_end = WINDOW_HEIGHT;
		}
		column_id++;
	}
}

static void draw_texture(t_cub3d *cub3d, t_ray ray, struct mlx_texture *texture)
{
	// TODO this is where you left off yo
	// start getting the right pixel color
	// then put that pixel on the screen
}

static void	draw_walls(t_cub3d *cub3d, t_ray *rays)
{
	int i;

	set_draw_values(rays);
	i = 0;
	while (i < NUM_RAYS)
	{
		if (rays[i].hit_wall_direction == NORTH)
			draw_texture(cub3d, rays[i], cub3d->map_data.north_wall);
		else if (rays[i].hit_wall_direction == SOUTH)
			draw_texture(cub3d, rays[i], cub3d->map_data.south_wall);
		else if (rays[i].hit_wall_direction == EAST)
			draw_texture(cub3d, rays[i], cub3d->map_data.east_wall);
		else if (rays[i].hit_wall_direction == WEST)
			draw_texture(cub3d, rays[i], cub3d->map_data.west_wall);
		i++;
	}
}

void	render(t_cub3d *cub3d_data)
{
	t_ray *rays;

	rays = cast_all_rays(cub3d_data);
	free(rays);
}

void	update_loop(void *data)
{
	t_cub3d	*cub3d_data;

	cub3d_data = data;
	//update_values()
	render(cub3d_data);
}
