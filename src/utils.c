/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:15:12 by cpost             #+#    #+#             */
/*   Updated: 2022/12/19 13:25:13 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_parser.h"
#include "cub3d_utils.h"
#include <stdlib.h>
#include "cub3d_render.h"
#include "math.h"

bool	is_wall_at_location(t_map map_data, float y, float x)
{
	int	mapGridX;
	int	mapGridY;

	if (x < 0 || y < 0
		|| x > map_data.n_column * TILE_SIZE
		|| x > map_data.n_column * TILE_SIZE)
		return (true);
	mapGridX = floor(x / TILE_SIZE);
	mapGridY = floor(y / TILE_SIZE);
	return (map_data.map[mapGridY][mapGridX] == 1);
}

void	*alloc_check(void *ptr)
{
	if (!ptr)
		exit_error("Malloc fail\n", 1);
	return (ptr);
}

void	exit_error(char *message, int exit_code)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	exit(exit_code);
}

double	normalize_angle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_1_PI);
	return (angle);
}