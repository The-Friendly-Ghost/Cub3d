/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 14:48:59 by cpost         #+#    #+#                 */
/*   Updated: 2023/01/18 15:32:31 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"
#include "cub3d_render.h"
#include "cub3d_utils.h"

float	get_scale(t_cub3d *cub3d)
{
	float	new_tilesize;

	if (cub3d->map_data.n_column > cub3d->map_data.n_row)
		new_tilesize = (WINDOW_WIDTH * MINI_SCALE) / cub3d->map_data.n_column;
	else
		new_tilesize = (WINDOW_HEIGHT * MINI_SCALE) / cub3d->map_data.n_row;
	return (new_tilesize / TILE_SIZE);
}
