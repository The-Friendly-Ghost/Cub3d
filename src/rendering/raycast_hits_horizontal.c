/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_hits_horizontal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:18:26 by merel             #+#    #+#             */
/*   Updated: 2023/01/03 10:45:50 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"
#include "cub3d_utils.h"
#include "libft.h"
#include <stdio.h>
#include "cub3d_render.h"

void	set_horizontal_step(t_ray *ray)
{
	ray->horizontal_step.y = TILE_SIZE;
	if (ray->isRayFacingUp)
		ray->horizontal_step.y *= -1;
	ray->horizontal_step.x = TILE_SIZE / tan(ray->rayAngle);
	if ((!ray->isRayFacingRight && ray->horizontal_step.x > 0)
		|| (ray->isRayFacingRight && ray->horizontal_step.x < 0))
		ray->horizontal_step.x *= -1;
	printf("horstepx = %f\nhorstepy = %f\n", ray->horizontal_step.x, ray->horizontal_step.y);
}

t_fVector2d	get_horizontal_intercept(t_ray *ray, t_player player)
{
	t_fVector2d horizontal_intercept;

	horizontal_intercept.y = floor(player.position.y / TILE_SIZE) * TILE_SIZE;
	if (!ray->isRayFacingRight)
		horizontal_intercept.y += TILE_SIZE;
	horizontal_intercept.x = player.position.x
		+ (horizontal_intercept.y - player.position.y) / tan(ray->rayAngle);
	printf("hor interept found\n");
	return (horizontal_intercept);
}

void	set_hor_wall_hit(t_ray *ray, t_cub3d *cub3d, t_fVector2d intercept)
{
	float	nextTouchX;
	float	nextTouchY;
	int		offset;
	
	nextTouchX = intercept.x;
	nextTouchY = intercept.y;
	offset = 0;
	if (ray->isRayFacingUp)
		offset = -1;
	// this windows width height thing is not correct, please see how to do correct screen res
	while (nextTouchX >= 0 && nextTouchX / TILE_SIZE <= WINDOW_WIDTH
		&& nextTouchY >= 0 && nextTouchY / TILE_SIZE <= WINDOW_HEIGHT)
	{
		printf("started checking hits\n");
		if (is_wall_at_location(cub3d->map_data, (nextTouchY + offset), nextTouchX))
		{
			ray->horizontal_wallHit.x = nextTouchX;
			ray->horizontal_wallHit.y = nextTouchY;
			ray->wasHitHorizontal = true;
			printf("hor wall hit found\n");
			return ;
		}
		nextTouchX += ray->horizontal_step.x;
		nextTouchY += ray->horizontal_step.y;
	}
	printf("hor wall hit not found\n");
	ray->wasHitHorizontal = false;
}

void	find_horizontal_wall_hit(t_ray *ray, t_cub3d *cub3d)
{
	t_fVector2d horizontal_intercept;

	printf("finding hor wall hit\n");
	horizontal_intercept = get_horizontal_intercept(ray, cub3d->player_data);
	set_horizontal_step(ray);
	set_hor_wall_hit(ray, cub3d, horizontal_intercept);
	
}