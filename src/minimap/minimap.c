/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:22:08 by merel             #+#    #+#             */
/*   Updated: 2023/01/03 11:55:53 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d_structs.h"
#include "cub3d_colors.h"
#include "cub3d_render.h"
#include "cub3d_utils.h"

static void	draw_square(t_cub3d *cub3d, float x, float y)
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
	while (y < y_start + (MINI_SCALE * TILE_SIZE))
	{
		x = x_start;
		while (x < x_start + (MINI_SCALE * TILE_SIZE))
		{
			mlx_put_pixel(cub3d->images.miniMap, x, y, black_converted);
			x++;
		}
		y++;
	}
	
}

void	draw_mini_map(t_cub3d *cub3d, t_map map, t_player player, t_ray *rays)
{
	int		x;
	int		y;
	float	stepx;
	float	stepy;
	
	(void) rays;
	(void) player;
	cub3d->images.miniMap = alloc_check(mlx_new_image(cub3d->mlx, map.n_column * TILE_SIZE * MINI_SCALE, map.n_row * TILE_SIZE * MINI_SCALE));
	y = 0;
	stepy = 0;
	while (y < map.n_row)
	{
		x = 0;
		stepx = 0;
		while (x < map.n_column)
		{
			if (map.map[y][x] == '1')
				draw_square(cub3d, stepx, stepy);
			stepx += (MINI_SCALE * TILE_SIZE);
			x++;
		}
		stepy += (MINI_SCALE * TILE_SIZE);
		y++;
	}
	mlx_image_to_window(cub3d->mlx, cub3d->images.miniMap, 0, 0);
}