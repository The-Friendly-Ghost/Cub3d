/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:38:17 by merel             #+#    #+#             */
/*   Updated: 2023/01/03 11:05:02 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
#include "cub3d_utils.h"
#include "cub3d_enums.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static void	turn_player(t_player *player)
{
	player->rotationAngle += player->turnDirection * player->rotationSpeed;
	//printf("player rotation = %f\n player turn direction= %f\n playerRotation speed = %f\n", player->rotationAngle, player->turnDirection, player->rotationSpeed);
}

static void	try_strafe_player(t_map *map_data, t_player *player)
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

static void	try_move_player(t_map *map_data, t_player *player)
{
	float	moveStep;
	float	new_y;
	float	new_x;

	moveStep = player->walkDirection * player->moveSpeed;
	new_y = player->position.y + moveStep * sin(player->rotationAngle);
	new_x = player->position.x + moveStep * cos(player->rotationAngle);
	if (is_wall_at_location(*map_data, new_y, new_x))
		return ;
	player->position.y = new_y;
	player->position.x = new_x;
}

/**
 * @brief movement forward, backward and turning left and right
 * @note THIS DOES NOT TAKE LEFT AND RIGHT MOVEMENT INTO ACCOUNT YET!!
 * 
 * @param keydata used to check which key was pressed
 * @param map_data used to check if the next step goes into a wall
 * @param player used to update the player location
 */
void	key_pressed_and_hold(mlx_key_data_t keydata, t_map *map_data, t_player *player)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		exit (0);
	if (keydata.key == MLX_KEY_W)
		player->walkDirection = -1;
	if (keydata.key == MLX_KEY_S)
		player->walkDirection = +1;
	if (keydata.key == MLX_KEY_A)
		player->strafeDirection = -1;
	if (keydata.key == MLX_KEY_D)
		player->strafeDirection = +1;
	if (keydata.key == MLX_KEY_LEFT)
		player->turnDirection = -1;
	if (keydata.key == MLX_KEY_RIGHT)
		player->turnDirection = +1;
	turn_player(player);
	try_move_player(map_data, player);
	try_strafe_player(map_data, player);
	//printf("pressed a key\n");
}

void	key_released(mlx_key_data_t keydata, t_player *player)
{
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
		player->walkDirection = 0;
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		player->strafeDirection = 0;
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		player->turnDirection = 0;
	//printf("released a button\n");
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*cub3d_data;

	cub3d_data = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		key_pressed_and_hold(keydata, &cub3d_data->map_data, &cub3d_data->player_data);
	if (keydata.action == MLX_RELEASE)
		key_released(keydata, &cub3d_data->player_data);
}
