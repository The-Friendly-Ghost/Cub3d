/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycaster.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 11:04:52 by mevan-de      #+#    #+#                 */
/*   Updated: 2023/01/10 16:23:27 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"
#include "cub3d_utils.h"
#include "libft.h"
#include "cub3d_render.h"
#include <limits.h>
#include <stdio.h>

/**
 * @brief Sets the distance to wall based on the closest wall hit (horizontal
 * or vertical). Also sets the other wall hit to false again, so it only says
 * true for the actual wall hit.
 * 
 * @param ray the ray to set the distance for
 * @param playerPos the current player position
 */
static void	set_distance_to_wall(t_ray *ray, t_fVector2d playerPos,
	float playerRotation)
{
	float	distance_hor;
	float	distance_vert;

	distance_hor = MAXFLOAT;
	distance_vert = MAXFLOAT;
	if (ray->was_hit_horizontal)
		distance_hor = get_dist_between_points(playerPos.x, playerPos.y,
				ray->horizontal_wall_hit.x, ray->horizontal_wall_hit.y);
	if (ray->was_hit_vertical)
		distance_vert = get_dist_between_points(playerPos.x, playerPos.y,
				ray->vertical_wall_hit.x, ray->vertical_wall_hit.y);
	if (distance_vert < distance_hor)
	{
		ray->distance = distance_vert;
		ray->was_hit_horizontal = false;
	}
	else
	{
		ray->distance = distance_hor;
		ray->was_hit_vertical = false;
	}
	ray->distance *= cos(ray->ray_angle - playerRotation);
}

static void	set_hit_wall_direction(t_ray *ray)
{
	if (ray->was_hit_horizontal)
	{
		if (ray->is_ray_facing_up)
			ray->hit_wall_direction = NORTH;
		else
			ray->hit_wall_direction = SOUTH;
		return ;
	}
	if (ray->is_ray_facing_right)
		ray->hit_wall_direction = EAST;
	else
		ray->hit_wall_direction = WEST;
}

static void	set_ray_values(t_cub3d *cub3d, t_ray *ray, float angle)
{
	ray->was_hit_vertical = false;
	ray->was_hit_horizontal = false;
	ray->ray_angle = normalize_angle(angle);
	ray->is_ray_facing_up = !(ray->ray_angle > 0 && ray->ray_angle < M_PI);
	ray->is_ray_facing_right = (ray->ray_angle < (0.5 * M_PI)
			|| ray->ray_angle > (1.5 * M_PI));
	find_horizontal_wall_hit(ray, cub3d);
	find_vertical_wall_hit(ray, cub3d);
	set_distance_to_wall(ray, cub3d->player_data.position,
		cub3d->player_data.rotation_angle);
	set_hit_wall_direction(ray);
}

t_ray	*cast_all_rays(t_cub3d *cub3d)
{
	int		i;
	double	ray_angle;
	t_ray	*rays;

	rays = alloc_check(ft_calloc(cub3d->num_rays + 1, sizeof(t_ray)));
	i = 0;
	ray_angle = cub3d->player_data.rotation_angle - (cub3d->fov / 2);
	while (i < cub3d->num_rays)
	{
		set_ray_values(cub3d, &rays[i], ray_angle);
		ray_angle += cub3d->fov / cub3d->num_rays;
		i++;
	}
	return (rays);
}
