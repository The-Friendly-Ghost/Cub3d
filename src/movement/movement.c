/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:38:17 by merel             #+#    #+#             */
/*   Updated: 2023/01/05 10:09:59 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
#include "cub3d_utils.h"
#include "cub3d_enums.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void	turn_player(t_player *player)
{
	player->rotationAngle += player->turnDirection
			* player->rotationSpeed;
	//printf("player rotation = %f\n player turn direction= %f\n playerRotation speed = %f\n", player->rotationAngle, player->turnDirection, player->rotationSpeed);
}

void	try_strafe_player(t_map *map_data, t_player *player)
{
	float	moveStep;
	float	new_y;
	float	new_x;

	moveStep = player->strafeDirection * player->moveSpeed;
	new_y = player->position.y
		+ sin(player->rotationAngle - M_PI_2) * moveStep;
	new_x = player->position.x
		+ cos(player->rotationAngle - M_PI_2) * moveStep;
	if (is_wall_at_location(*map_data, new_y, new_x))
		return ;
	player->position.y = new_y;
	player->position.x = new_x;
}

void	try_move_player(t_map *map_data, t_player *player)
{
	float	moveStep;
	float	new_y;
	float	new_x;

	moveStep = player->walkDirection * player->moveSpeed;
	new_x = player->position.x + cos(player->rotationAngle) * moveStep;
	new_y = player->position.y + sin(player->rotationAngle) * moveStep;
	if (is_wall_at_location(*map_data, new_y, new_x))
		return ;
	player->position.y = new_y;
	player->position.x = new_x;
}
