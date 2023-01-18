/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_loop.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 12:02:12 by mevan-de      #+#    #+#                 */
/*   Updated: 2023/01/18 15:26:57 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_utils.h"
#include "cub3d_render.h"
#include "cub3d_structs.h"
#include "cub3d_movement.h"

#include "libft.h"
#include <stdlib.h>
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

static void	draw_walls(t_cub3d *cub3d, t_ray *rays)
{
	int	x;

	set_draw_values(rays, cub3d->distance_to_plane, cub3d->num_rays);
	x = 0;
	while (x < cub3d->num_rays)
	{
		if (rays[x].hit_wall_direction == NORTH)
			draw_column(cub3d, rays[x], cub3d->map_data.north_wall, x);
		else if (rays[x].hit_wall_direction == SOUTH)
			draw_column(cub3d, rays[x], cub3d->map_data.south_wall, x);
		else if (rays[x].hit_wall_direction == EAST)
			draw_column(cub3d, rays[x], cub3d->map_data.east_wall, x);
		else if (rays[x].hit_wall_direction == WEST)
			draw_column(cub3d, rays[x], cub3d->map_data.west_wall, x);
		x++;
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
		draw_rays(rays, cub3d_data, cub3d_data->num_rays);
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
