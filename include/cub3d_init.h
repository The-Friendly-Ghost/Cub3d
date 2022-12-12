/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_init.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/12 14:23:17 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/12/12 14:31:44 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_INIT_H
# define CUB3D_INIT_H
# include "cub3d_structs.h"

/**
 * @brief initialize all player values for starting the game.
 * @param player_data the place to store all player data
 * @param map the parsed map
 * @return nothing, but will exit the program when something fails
*/
void	init_player_vars(t_player *player_data, char **map);

#endif