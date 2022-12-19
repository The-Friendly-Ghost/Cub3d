/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_movement.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:39:59 by merel             #+#    #+#             */
/*   Updated: 2022/12/19 13:28:13 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MOVEMENT_H
# define CUB3D_MOVEMENT_H
# include "../lib/MLX42/include/MLX42/MLX42.h"

/**
 * @brief the event that receives when a key has been pressed (or is being held)
 * 
 * @param keydata mlx keydata that contains the key info
 * @param param a pointer to something, advised to send cub3d_data, to be used
 * in this and subsequent functions.
 */
void	key_hook(mlx_key_data_t keydata, void *param);

#endif