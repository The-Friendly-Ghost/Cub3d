/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 11:21:08 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/12/06 13:12:43 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_utils.h"
#include "cub3d_MLX.h"
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
	}
}

void	init_mlx(t_cub3d cub3d_data)
{
	cub3d_data.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D", true);
	if (!cub3d_data.mlx)
		exit_error("Failed to init MLX\n", 1);
	mlx_key_hook(cub3d_data.mlx, key_hook, &cub3d_data);
	//mlx_loop_hook(cub3d_data.mlx, NULL, &cub3d_data);
	mlx_loop(cub3d_data.mlx);
	printf("hello\n");
}
