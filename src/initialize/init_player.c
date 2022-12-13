/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:39:40 by mevan-de          #+#    #+#             */
/*   Updated: 2022/12/13 10:42:14 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"
#include "cub3d_utils.h"

static t_Vector2d	get_player_start_position(char **map)
{
	t_Vector2d	position;

	position.x = 0;
	position.y = 0;
	while (map[position.y])
	{
		while (map[position.y][position.x])
		{
			if (map[position.y][position.x] == 'N'
				|| map[position.y][position.x] == 'S'
				|| map[position.y][position.x] == 'E'
				|| map[position.y][position.x] == 'W')
				return (position);
			position.x++;
		}
		position.y++;
	}
	return (position);
}

static bool	set_player_position(t_player *player_data, t_Vector2d position)
{
	player_data->position.x = position.x;
	player_data->position.y = position.y;
	return (true);
}

void	init_player_vars(t_player *player_data, char **map)
{
	if (!map)
		exit_error("Map value in init_player_vars is NULL\n", 1);
	if (!set_player_position(player_data, get_player_start_position(map)))
		exit_error("Failed to set player position, check map\n", 1);
	// set player rotation
}
