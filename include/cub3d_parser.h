/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_parser.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 11:13:37 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/05 13:19:33 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSER_H
# define CUB3D_PARSER_H
# include "cub3d_structs.h"

/**
#=====================================#
#============= Functions =============#
#=====================================#
*/

/**
 * @brief Function that reads the information from the .cub file.
 * @param map Pointer to the struct that has all the map information in it
 * @return Nothing
 * @note
 */
void	parse_map(t_map *map);

/**
 * @brief Validates whether a file exists and ends with .cub
 * @param file Filename to be validated
 * @return True if file exits and is a .cub file. Else returns false.
 * @note
 */
void	validate_filetype(char *file, t_map *map);

#endif
