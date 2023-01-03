/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:42:22 by merel             #+#    #+#             */
/*   Updated: 2023/01/03 10:49:46 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <struct.h>
#include "libft.h"
#include "cub3d_render.h"
#include <stdio.h>

bool	is_wall_at_location(t_map map_data, float y, float x)
{
	int	mapGridX;
	int	mapGridY;

	printf("checking if wall at location\n");
	if (x <= 0 || y <= 0
		|| x / TILE_SIZE >= map_data.n_column
		|| y / TILE_SIZE >= map_data.n_row)
		return (true);
	mapGridX = floor(x / TILE_SIZE);
	mapGridY = floor(y / TILE_SIZE);
	return (map_data.map[mapGridY][mapGridX] == '1');
}

double	normalize_angle(double angle)
{
	if (angle > (2 * M_PI))
		angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_1_PI);
	return (angle);
}

float get_dist_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
}