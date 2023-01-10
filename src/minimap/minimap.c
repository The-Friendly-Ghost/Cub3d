/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 11:22:08 by merel         #+#    #+#                 */
/*   Updated: 2023/01/10 15:33:31 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d_structs.h"
#include "cub3d_colors.h"
#include "cub3d_render.h"
#include "cub3d_utils.h"

static void	draw_line(mlx_image_t *image, t_player player, float endX, float endY)
{
	float	length;
	float	stepX;
	float	stepY;
	t_rgb	red;

	red.blue = 0;
	red.red = 255;
	red.green = 0;
	length = get_dist_between_points((player.position.x * MINI_SCALE), 
		(player.position.y * MINI_SCALE), endX, endY);
	stepX = (endX - MINI_SCALE * player.position.x) / length;
	stepY = (endY - MINI_SCALE * player.position.y) / length;
	//printf("length line = %f\n", length);
	while (length > 0)
	{
		mlx_put_pixel(image, endX, endY, convert_rgb_to_int(red));
		endY -= stepY;
		endX -= stepX;
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
	//printf("starting on square\n");
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
	//printf("done with square\n");
	
}

// void	create_player_image(t_cub3d *cub3d, float x, float y){
	
// }

void	draw_rays(t_player player, t_ray *rays, mlx_image_t *ray_image)
{
	int	i;

	i = 0;
	while (i < NUM_RAYS - 1)
	{
		if (rays[i].wasHitHorizontal)
			draw_line(ray_image, player, rays[i].horizontal_wallHit.x * MINI_SCALE,
				rays[i].horizontal_wallHit.y * MINI_SCALE);
		else if (rays[i].wasHitVertical)
			draw_line(ray_image, player, rays[i].vertical_wallHit.x * MINI_SCALE,
				rays[i].vertical_wallHit.y * MINI_SCALE);
		i++;
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
	cub3d->images.miniMap = alloc_check(mlx_new_image(cub3d->mlx,
		map.n_column * TILE_SIZE * MINI_SCALE + 1,
		map.n_row * TILE_SIZE * MINI_SCALE + 1));
	cub3d->images.rays = NULL;
	y = 0;
	stepy = 0;
	while (y < map.n_row)
	{
		x = 0;
		stepx = 0;
		while (x < map.n_column)
		{
			if (map.map[y][x] == '1')
				draw_square(cub3d->images.miniMap, stepx, stepy,
					(MINI_SCALE * TILE_SIZE));
			stepx += (MINI_SCALE * TILE_SIZE);
			x++;
		}
		stepy += (MINI_SCALE * TILE_SIZE);
		y++;
	}
	mlx_image_to_window(cub3d->mlx, cub3d->images.miniMap, 0, 0);
}