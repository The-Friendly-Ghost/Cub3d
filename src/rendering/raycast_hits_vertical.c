/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast_hits_vertical.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/02 11:18:26 by merel         #+#    #+#                 */
/*   Updated: 2023/01/10 12:51:42 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"
#include "cub3d_utils.h"
#include "libft.h"
#include "cub3d_render.h"
#include "stdio.h"

//use check x/y instead of nextTouch also for horz
void	set_vert_wall_hit(t_ray *ray, t_cub3d *cub3d, t_fVector2d intercept)
{
	float	checkX;
	
	while (is_intercept_in_range(intercept, cub3d->map_data))
	{
		checkX = intercept.x;
		if (!ray->isRayFacingRight)
			checkX--;
		if (is_wall_at_location(cub3d->map_data, intercept.y, checkX))
		{
			ray->wasHitVertical = true;
			ray->vertical_wallHit.x = intercept.x;
			ray->vertical_wallHit.y = intercept.y;
			return ;
		}
		intercept.x += ray->vertical_step.x;
		intercept.y += ray->vertical_step.y;
	}
	ray->wasHitVertical = false;
}

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
		+ (vertical_intercept.x - player.position.x) * tan(ray->rayAngle);
	return (vertical_intercept);
}

void	find_vertical_wall_hit(t_ray *ray, t_cub3d *cub3d)
{
	t_fVector2d vertical_intercept;

	vertical_intercept = get_vertical_intercept(ray, cub3d->player_data);
	set_vertical_step(ray);
	set_vert_wall_hit(ray, cub3d, vertical_intercept);
}
