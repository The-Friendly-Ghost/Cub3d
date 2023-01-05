/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_movement.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:39:59 by merel             #+#    #+#             */
/*   Updated: 2023/01/05 10:10:10 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MOVEMENT_H
# define CUB3D_MOVEMENT_H
# include "../lib/MLX42/include/MLX42/MLX42.h"

/**

*/
void	key_loop(void *param);

void	turn_player(t_player *player);

void	try_strafe_player(t_map *map_data, t_player *player);

void	try_move_player(t_map *map_data, t_player *player);

#endif
