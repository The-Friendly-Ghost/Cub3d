/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycaster.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 11:04:52 by mevan-de      #+#    #+#                 */
/*   Updated: 2023/01/09 16:47:14 by mevan-de      ########   odam.nl         */
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
static void	set_distance_to_wall(t_ray *ray, t_fVector2d playerPos, float playerRotation)
{
	float	distance_hor;
	float	distance_vert;

	distance_hor = MAXFLOAT;
	distance_vert = MAXFLOAT;
	if (ray->wasHitHorizontal)
		distance_hor = get_dist_between_points(playerPos.x, playerPos.y,
			ray->horizontal_wallHit.x,ray->horizontal_wallHit.y);
	if (ray->wasHitVertical)
		distance_vert = get_dist_between_points(playerPos.x, playerPos.y,
			ray->vertical_wallHit.x,ray->vertical_wallHit.y);
	if (distance_vert < distance_hor)
	{
		ray->distance = distance_vert;
		ray->wasHitHorizontal = false;
	}
	else
	{
		ray->distance = distance_hor;
		ray->wasHitVertical = false;
	}
	ray->distance *= cos(ray->rayAngle - playerRotation);
	//printf("distance after correction = %f\n", ray->distance);
}

static void set_hit_wall_direction(t_ray *ray)
{
	if (ray->wasHitHorizontal)
	{
		if (ray->isRayFacingUp)
			ray->hit_wall_direction = NORTH;
		else
			ray->hit_wall_direction = SOUTH;
		return ;
	}
	if (ray->isRayFacingRight)
		ray->hit_wall_direction = EAST;
	else
		ray->hit_wall_direction = WEST;
}

static void	set_ray_values(t_cub3d *cub3d, t_ray *ray, float angle)
{
	//printf("setting ray value\n");
	ray->wasHitVertical = false;
	ray->wasHitHorizontal = false;
	ray->rayAngle = normalize_angle(angle);
	ray->isRayFacingUp = !(ray->rayAngle > 0 && ray->rayAngle < M_PI);
	ray->isRayFacingRight = ray->rayAngle < (0.5 * M_PI) 
				|| ray->rayAngle > (1.5 * M_PI);
	find_horizontal_wall_hit(ray, cub3d);
	find_vertical_wall_hit(ray, cub3d);
	set_distance_to_wall(ray, cub3d->player_data.position, cub3d->player_data.rotationAngle);
	set_hit_wall_direction(ray);
}

// 1. create an array of t_rays for num_rays
// 2. cast all rays to find the correct distances
// 3. render 3d projected walls, for every ray
t_ray	*cast_all_rays(t_cub3d *cub3d)
{
	int		i;
	double	rayAngle;
	t_ray	*rays;

	rays = alloc_check(ft_calloc(NUM_RAYS, sizeof(t_ray)));
	i = 0;
	rayAngle = cub3d->player_data.rotationAngle - (FOV / 2);
	while (i < NUM_RAYS)
	{ 
		set_ray_values(cub3d, &rays[i], rayAngle);
		rayAngle += FOV / NUM_RAYS * WALL_STRIP_WIDTH;
		//printf("rayAngle = %f\n", rayAngle);
		i++;
	}
	return (rays);
}
