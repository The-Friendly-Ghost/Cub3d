/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/02 10:42:22 by merel         #+#    #+#                 */
/*   Updated: 2023/01/10 16:36:13 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <struct.h>
#include "libft.h"
#include "cub3d_render.h"
#include <stdio.h>

bool	is_wall_at_location(t_map map_data, float y, float x)
{
	int	map_grid_x;
	int	map_grid_y;

	if (x <= 0 || y <= 0
		|| x / TILE_SIZE >= map_data.n_column
		|| y / TILE_SIZE >= map_data.n_row)
		return (true);
	map_grid_x = floor(x / TILE_SIZE);
	map_grid_y = floor(y / TILE_SIZE);
	return (map_data.map[map_grid_y][map_grid_x] == '1');
}

double	normalize_angle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

float	get_dist_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
}

bool	is_intercept_in_range(t_fVector2d intercept, t_map map_data)
{
	return (
		intercept.x >= 0
		&& intercept.x / TILE_SIZE <= TILE_SIZE * map_data.n_column
		&& intercept.y >= 0
		&& intercept.y / TILE_SIZE <= TILE_SIZE * map_data.n_row);
}
