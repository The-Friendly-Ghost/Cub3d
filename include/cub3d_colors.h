/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_colors.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 11:43:49 by merel         #+#    #+#                 */
/*   Updated: 2023/01/15 16:04:31 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_COLORS_H
# define CUB3D_COLORS_H
# include "cub3d_structs.h"

/**
 * @brief Converts rgb to int (currently with an alpha of 1)
 * 
 * @param color the rgb struct to be passed on
 * @return an int with the correct value for the color
 */
int	convert_rgb_to_int(t_rgb color);

int	get_colour_from_pixel(u_int8_t *pixel);

#endif
