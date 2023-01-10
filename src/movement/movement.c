/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 12:38:17 by merel         #+#    #+#                 */
/*   Updated: 2023/01/10 16:33:02 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "cub3d_utils.h"
#include "cub3d_enums.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void	turn_player(t_player *player)
{
	player->rotation_angle += player->turn_direction
		* player->rotation_speed;
	player->rotation_angle = normalize_angle(player->rotation_angle);
}

void	try_strafe_player(t_map *map_data, t_player *player)
{
	float	move_step;
	float	new_y;
	float	new_x;

	move_step = player->strafe_direction * player->move_speed;
	new_y = player->position.y
		+ sin(player->rotation_angle - M_PI_2) * move_step;
	new_x = player->position.x
		+ cos(player->rotation_angle - M_PI_2) * move_step;
	if (is_wall_at_location(*map_data, new_y, new_x))
		return ;
	player->position.y = new_y;
	player->position.x = new_x;
}

void	try_move_player(t_map *map_data, t_player *player)
{
	float	move_step;
	float	new_y;
	float	new_x;

	move_step = player->walk_direction * player->move_speed;
	new_x = player->position.x + cos(player->rotation_angle) * move_step;
	new_y = player->position.y + sin(player->rotation_angle) * move_step;
	if (is_wall_at_location(*map_data, new_y, new_x))
		return ;
	player->position.y = new_y;
	player->position.x = new_x;
}
