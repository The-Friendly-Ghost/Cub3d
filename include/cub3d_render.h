/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_render.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 11:14:03 by mevan-de      #+#    #+#                 */
/*   Updated: 2023/01/10 15:31:01 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MLX_H
# define CUB3D_MLX_H
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "cub3d_structs.h"
# include <math.h>

# define TILE_SIZE 32
# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 512
# define FOV_ANGLE 60
# define FOV (FOV_ANGLE * (M_PI / 180))
# define WALL_STRIP_WIDTH 1
# define NUM_RAYS (WINDOW_WIDTH / WALL_STRIP_WIDTH)
# define MINI_SCALE 0.2

/**
 * @brief Initialize all MLX related things: Window, Keyhooks, loop, loophooks.
 * @param cube3d_data all data needed for the project to run
 * @return Nothing
 */
void	init_mlx(t_cub3d *cub3d_data);

/**
 * @brief mlx loop that continuously gets called,
 * used for all the calls for drawing
 * @param data all game data needed for the rendering
 * @return Nothing
*/
void	update_loop(void *data);

/**
 * @brief Creates an array of ray structs with all the data needed for 
 * drawing.
 * 
 * @param cub3d all cub3d data
 * @return t_ray* array of rays with all important values set
 */
t_ray	*cast_all_rays(t_cub3d *cub3d);

/**
 * @brief finds and sets the horizontal wall hits in the ray. Also sets
 * if a horizontal wall hit was found.
 * 
 * @param ray the ray to be checked
 * @param cub3d cub3d data for the map and player data
 */
void	find_horizontal_wall_hit(t_ray *ray, t_cub3d *cub3d);

/**
 * @brief finds and sets the vertical wall hits in the ray. Also sets
 * if a vertical wall hit was found.
 * 
 * @param ray the ray to be checked
 * @param cub3d cub3d data for the map and player data
 */
void	find_vertical_wall_hit(t_ray *ray, t_cub3d *cub3d);

/**
 * @brief checks if the intercept is in range, used for checking the next intercept
 * for both vertical and horizontal intercepts.
 * 
 * @param intercept the place on the map to check
 * @param map data used to check the n_row and n_column
 * @return true if it's a valid place on the map, false if it's outside the map's 
 * range
*/
bool	is_intercept_in_range(t_fVector2d intercept, t_map map_data);

#endif