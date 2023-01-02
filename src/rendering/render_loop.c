/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:02:12 by mevan-de          #+#    #+#             */
/*   Updated: 2023/01/02 12:36:22 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_utils.h"
#include "cub3d_render.h"
#include "cub3d_structs.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static void	draw_walls(t_cub3d *cub3d, t_ray *rays)
{
	int	column_id;

	column_id = 0;
	while (column_id < NUM_RAYS)
	{
		column_id++;
	}
}

void	render(t_cub3d *cub3d_data)
{
	t_ray *rays;

	rays = cast_all_rays(cub3d_data);
	free(rays);
}

void	update_loop(void *data)
{
	t_cub3d	*cub3d_data;

	cub3d_data = data;
	//update_values()
	render(cub3d_data);
}
