/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_loop.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 12:02:12 by mevan-de      #+#    #+#                 */
/*   Updated: 2023/01/10 12:54:42 by mevan-de      ########   odam.nl         */
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

static void set_draw_values(t_ray *rays)
{
	int		column_id;
	float	distanceToPlane;
	t_ray	*ray;

	column_id = 0;
	distanceToPlane = (WINDOW_WIDTH / 2) / tan(FOV / 2);
	while (column_id < NUM_RAYS)
	{
		ray = &rays[column_id];
		//printf("raydistance= %f\n", ray->distance);
		ray->wall_height = (TILE_SIZE / ray->distance) * distanceToPlane;
		//printf("distance to plane = %f\n", distanceToPlane);
		ray->draw_start = (WINDOW_HEIGHT / 2) - (ray->wall_height / 2);
		ray->draw_end = ray->draw_start + ray->wall_height;
			//printf("start = %f\nend = %f", ray.draw_start, ray.draw_end);
		if (ray->wall_height > WINDOW_HEIGHT)
		{
			ray->draw_start = 0;
			ray->draw_end = WINDOW_HEIGHT;
		}
		column_id++;
	}
}

static void draw_texture(t_cub3d *cub3d, t_ray ray, struct mlx_texture *texture, int x)
{
	// TODO this is where you left off yo
	// start getting the right pixel color
	// then put that pixel on the screen
	(void) texture;
	t_rgb	white;
	int	width;

	white.blue = 255;
	white.green = 255;
	white.red = 255;
	x = x * WALL_STRIP_WIDTH;
	while (ray.draw_start < ray.draw_end)
	{
		width = 0;
		while (width < WALL_STRIP_WIDTH)
		{
			mlx_put_pixel(cub3d->images.walls, x + width, ray.draw_start, convert_rgb_to_int(white));
			width++;
		}
		//printf("putting pixel\n");
		ray.draw_start++;
	}
}

static void	draw_walls(t_cub3d *cub3d, t_ray *rays)
{
	int i;

	set_draw_values(rays);
	i = 0;
	while (i < NUM_RAYS - 2)
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
	t_ray *rays;
	bool	drawMiniRays;

	drawMiniRays = true;
	rays = cast_all_rays(cub3d_data);
	if (cub3d_data->images.walls)
	{
		mlx_delete_image(cub3d_data->mlx, cub3d_data->images.walls);
		cub3d_data->images.walls = alloc_check(mlx_new_image(cub3d_data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT));
	}
	draw_walls(cub3d_data, rays);
	mlx_image_to_window(cub3d_data->mlx, cub3d_data->images.walls, 0, 0);
	mlx_set_instance_depth(cub3d_data->images.walls->instances, 3);
	mlx_set_instance_depth(cub3d_data->images.miniMap->instances, 4);
	//cub3d_data->images.walls->instances[0].z = 3;
//	cub3d_data->images.miniMap->instances[0].z = 4;
	if (drawMiniRays)
	{
		if (cub3d_data->images.rays)
			mlx_delete_image(cub3d_data->mlx, cub3d_data->images.rays);
		cub3d_data->images.rays = alloc_check(mlx_new_image(cub3d_data->mlx,
			cub3d_data->map_data.n_column * TILE_SIZE * MINI_SCALE,
			cub3d_data->map_data.n_row * TILE_SIZE * MINI_SCALE));
		draw_rays(cub3d_data->player_data, rays, cub3d_data->images.rays);
		mlx_image_to_window(cub3d_data->mlx, cub3d_data->images.rays, 0, 0);
		cub3d_data->images.rays->instances[0].z = 5;
	}
	free(rays);
}

void	update_loop(void *data)
{
	t_cub3d	*cub3d_data;

	cub3d_data = data;
	turn_player(&cub3d_data->player_data);
	try_move_player(&cub3d_data->map_data, &cub3d_data->player_data);
	try_strafe_player(&cub3d_data->map_data, &cub3d_data->player_data);
	//update_values()
	//printf("turn direction = %i\n", cub3d_data->player_data.turnDirection);
	render(cub3d_data);
	
}
