/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 11:21:08 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/12/12 14:14:33 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_utils.h"
#include "cub3d_render.h"
#include "cub3d_structs.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h> 




void	key_hook(mlx_key_data_t keydata, void *param)
{
	(void) param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			exit (0);
		// if (keydata.key == MLX_KEY_W)
		// if (keydata.key == MLX_KEY_S)
		// if (keydata.key == MLX_KEY_A)
		// if (keydata.key == MLX_KEY_D)
		// if (keydata.key == MLX_KEY_LEFT)
		// if (keydata.key == MLX_KEY_RIGHT)
	}
}

void	init_mlx(t_cub3d cub3d_data)
{
	cub3d_data.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D", true);
	if (!cub3d_data.mlx)
		exit_error("Failed to init MLX\n", 1);
	mlx_key_hook(cub3d_data.mlx, key_hook, &cub3d_data);
	mlx_loop_hook(cub3d_data.mlx, update_loop, &cub3d_data);
	mlx_loop(cub3d_data.mlx);
	mlx_terminate(cub3d_data.mlx);
}
