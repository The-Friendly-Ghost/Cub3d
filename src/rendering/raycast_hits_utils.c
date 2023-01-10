/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast_hits_utils.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:46:42 by mevan-de      #+#    #+#                 */
/*   Updated: 2023/01/10 12:48:46 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"
#include "cub3d_render.h"

bool	is_intercept_in_range(t_fVector2d intercept, t_map map_data)
{
	return (
		intercept.x >= 0
		&& intercept.x / TILE_SIZE <= TILE_SIZE * map_data.n_column
		&& intercept.y >= 0
		&& intercept.y / TILE_SIZE <= TILE_SIZE * map_data.n_row);
}