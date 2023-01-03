/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_hits_vertical.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:18:26 by merel             #+#    #+#             */
/*   Updated: 2023/01/02 16:28:19 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"
#include "cub3d_utils.h"
#include "libft.h"
#include "cub3d_render.h"

void	set_vertical_step(t_ray *ray)
{
	ray->vertical_step.x = TILE_SIZE;
	if (!ray->isRayFacingRight)
		ray->vertical_step.x *= -1;
	ray->vertical_step.y = TILE_SIZE * tan(ray->rayAngle);
	if ((ray->isRayFacingUp && ray->vertical_step.y > 0)
		|| (!ray->isRayFacingUp && ray->vertical_step.y < 0))
		ray->vertical_step.y *= -1;
}

t_fVector2d	get_vertical_intercept(t_ray *ray, t_player player)
{
	t_fVector2d vertical_intercept;

	vertical_intercept.x = floor(player.position.x / TILE_SIZE) * TILE_SIZE;
	if (ray->isRayFacingRight)
		vertical_intercept.x += TILE_SIZE;
	vertical_intercept.y = player.position.y
		+ (vertical_intercept.x - player.position.x) / tan(ray->rayAngle);
	return (vertical_intercept);
}

void	set_vert_wall_hit(t_ray *ray, t_cub3d *cub3d, t_fVector2d intercept)
{
	float	nextTouchX;
	float	nextTouchY;
	int		offset;
	
	nextTouchX = intercept.x;
	nextTouchY = intercept.y;
	offset = 0;
	if (!ray->isRayFacingRight)
		offset = -1;
	// this windows width height thing is not correct, please see how to do correct screen res
	while (nextTouchX >= 0 && nextTouchX / TILE_SIZE <= WINDOW_WIDTH
		&& nextTouchY >= 0 && nextTouchY / TILE_SIZE <= WINDOW_HEIGHT)
	{
		if (is_wall_at_location(cub3d->map_data, (nextTouchY - 0.001), (nextTouchX + offset)))
		{
			ray->vertical_wallHit.x = nextTouchX;
			ray->vertical_wallHit.y = nextTouchY;
			ray->wasHitVertical = true;
			return ;
		}
		nextTouchX += ray->vertical_step.x;
		nextTouchY += ray->vertical_step.y;
	}
	ray->wasHitVertical = false;
}

void	find_vertical_wall_hit(t_ray *ray, t_cub3d *cub3d)
{
	t_fVector2d vertical_intercept;

	vertical_intercept = get_vertical_intercept(ray, cub3d->player_data);
	set_vertical_step(ray);
	set_vert_wall_hit(ray, cub3d, vertical_intercept);
}