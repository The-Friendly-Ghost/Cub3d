/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:13:37 by cpost             #+#    #+#             */
/*   Updated: 2022/12/19 13:26:42 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_UTILS_H
# define CUB3D_UTILS_H
#include "cub3d_structs.h"

/**
#=====================================#
#============= Functions =============#
#=====================================#
*/

/**
 * @brief Function that exits the program. But before it does that, it prints
 * "Error" followed by an error message.
 * @param message The error message to be printed
 * @param exit_code The exit code that the program has to be exited with
 * @return Nothing
 * @note
 */
void	exit_error(char *message, int exit_code);

/**
 * @brief Function that can be used to protect memory allocation.
 * Will exit the program if the pointer is NULL.
 * @param ptr a pointer to the allocated memory
 * @returns the allocated pointer if it's not null
 * @note example: str = alloc_check(malloc(sizeof(char) * 10))
 */
void	*alloc_check(void *ptr);

/**
 * @brief checks if a wall is on the location you give it. The location is
 * the actual pixel distance, not the grid location (this will be floored)
 * @param map_data the map, the nr_row and the nr_column will be used to check
 * if there is a wall
 * @param y	the y location
 * @param x the x location
 * @returns true if a 1 is on the corresponding location on the map
 */
bool	is_wall_at_location(t_map map_data, float y, float x);

/**
 * @brief normalizes the angle to be in 0 - 2PI range
 * 
 * @param angle the angle that needs to be normalized
 * @returns the normalized angle...
 */
double	normalize_angle(double angle);

#endif
