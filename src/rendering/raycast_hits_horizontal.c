/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast_hits_horizontal.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/02 11:18:26 by merel         #+#    #+#                 */
/*   Updated: 2023/01/10 16:31:09 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"
#include "cub3d_utils.h"
#include "libft.h"
#include <stdio.h>
#include "cub3d_render.h"

void	set_hor_wall_hit(t_ray *ray, t_cub3d *cub3d, t_fVector2d intercept)
{
	float	check_y;

	while (is_intercept_in_range(intercept, cub3d->map_data))
	{
		check_y = intercept.y;
		if (ray->is_ray_facing_up)
			check_y--;
		if (is_wall_at_location(cub3d->map_data, check_y, intercept.x))
		{
			ray->was_hit_horizontal = true;
			ray->horizontal_wall_hit.x = intercept.x;
			ray->horizontal_wall_hit.y = intercept.y;
			return ;
		}
		intercept.x += ray->horizontal_step.x;
		intercept.y += ray->horizontal_step.y;
	}
	ray->was_hit_horizontal = false;
}

void	set_horizontal_step(t_ray *ray)
{
	ray->horizontal_step.y = TILE_SIZE;
	if (ray->is_ray_facing_up)
		ray->horizontal_step.y *= -1;
	ray->horizontal_step.x = TILE_SIZE / tan(ray->ray_angle);
	if ((!ray->is_ray_facing_right && ray->horizontal_step.x > 0)
		|| (ray->is_ray_facing_right && ray->horizontal_step.x < 0))
		ray->horizontal_step.x *= -1;
}

t_fVector2d	get_horizontal_intercept(t_ray *ray, t_player player)
{
	t_fVector2d	horizontal_intercept;

	horizontal_intercept.y = floor(player.position.y / TILE_SIZE) * TILE_SIZE;
	if (!ray->is_ray_facing_up)
		horizontal_intercept.y += TILE_SIZE;
	horizontal_intercept.x = player.position.x
		+ (horizontal_intercept.y - player.position.y) / tan(ray->ray_angle);
	return (horizontal_intercept);
}

void	find_horizontal_wall_hit(t_ray *ray, t_cub3d *cub3d)
{
	t_fVector2d	horizontal_intercept;

	horizontal_intercept = get_horizontal_intercept(ray, cub3d->player_data);
	set_horizontal_step(ray);
	set_hor_wall_hit(ray, cub3d, horizontal_intercept);
}
