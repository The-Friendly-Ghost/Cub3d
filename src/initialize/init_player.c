/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 13:39:40 by mevan-de      #+#    #+#                 */
/*   Updated: 2023/01/19 14:10:22 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"
#include "cub3d_utils.h"
#include <math.h>
#include <stdio.h>
#include "cub3d_render.h"
#include "cub3d_movement.h"

static t_Vector2d	get_player_start_coordinates(char **map)
{
	t_Vector2d	position;

	position.y = 0;
	while (map[position.y])
	{
		position.x = 0;
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

static char	get_player_start_direction(char **map)
{
	t_Vector2d	start_pos;

	start_pos = get_player_start_coordinates(map);
	return (map[start_pos.y][start_pos.x]);
}

static bool	set_player_position(t_player *player_data, t_Vector2d position)
{
	player_data->position.x = position.x * TILE_SIZE + (0.5 * TILE_SIZE);
	player_data->position.y = position.y * TILE_SIZE + (0.5 * TILE_SIZE);
	return (true);
}

static bool	set_player_init_rotation(t_player *player_data, char **map)
{
	char	direction;

	direction = get_player_start_direction(map);
	if (direction == 'N')
		player_data->rotation_angle = M_PI * 1.5;
	else if (direction == 'E')
		player_data->rotation_angle = M_PI * 2;
	else if (direction == 'S')
		player_data->rotation_angle = M_PI * 0.5;
	else if (direction == 'W')
		player_data->rotation_angle = M_PI;
	else
		return (false);
	return (true);
}

void	init_player_vars(t_player *player_data, char **map)
{
	if (!map)
		exit_error("Map value in init_player_vars is NULL", 1);
	if (!set_player_position(player_data, get_player_start_coordinates(map)))
		exit_error("Failed to set player position, check map", 1);
	if (!set_player_init_rotation(player_data, map))
		exit_error("Failed to set initial player rotation", 1);
	player_data->turn_direction = 0;
	player_data->walk_direction = 0;
	player_data->strafe_direction = 0;
	player_data->rotation_speed = TURN_SPEED * (M_PI / 180);
	player_data->move_speed = MOVE_SPEED;
}
