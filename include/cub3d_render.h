/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_render.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 11:14:03 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/12/12 13:48:38 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MLX_H
# define CUB3D_MLX_H
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "cub3d_structs.h"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 1024

/**
 * @brief Initialize all MLX related things: Window, Keyhooks, loop, loophooks.
 * @param cube3d_data all data needed for the project to run
 * @return Nothing
 */
void	init_mlx(t_cub3d cub3d_data);

/**
 * @brief mlx loop that continuously gets called,
 * used for all the calls for drawing
 * @param data all game data needed for the rendering
 * @return Nothing
*/
void	update_loop(void *data);

#endif