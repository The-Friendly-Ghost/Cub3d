/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 10:07:10 by merel         #+#    #+#                 */
/*   Updated: 2023/01/10 16:29:43 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "cub3d_utils.h"
#include "cub3d_enums.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void	check_key_pressed(mlx_t *mlx, t_player *player)
{
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		exit (0);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		player->walk_direction = 1;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		player->walk_direction = -1;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		player->strafe_direction = 1;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		player->strafe_direction = -1;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		player->turn_direction = -1;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		player->turn_direction = +1;
}

void	check_key_released(mlx_t *mlx, t_player *player)
{
	if (!mlx_is_key_down(mlx, MLX_KEY_W) && !mlx_is_key_down(mlx, MLX_KEY_S))
		player->walk_direction = 0;
	if (!mlx_is_key_down(mlx, MLX_KEY_A) && !mlx_is_key_down(mlx, MLX_KEY_D))
		player->strafe_direction = 0;
	if (!mlx_is_key_down(mlx, MLX_KEY_LEFT)
		&& !mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		player->turn_direction = 0;
}

void	key_loop(void *param)
{
	t_cub3d	*cub3d_data;

	cub3d_data = param;
	check_key_pressed(cub3d_data->mlx, &cub3d_data->player_data);
	check_key_released(cub3d_data->mlx, &cub3d_data->player_data);
}
