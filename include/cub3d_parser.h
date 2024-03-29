/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_parser.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 11:13:37 by cpost         #+#    #+#                 */
/*   Updated: 2023/01/19 18:58:00 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSER_H
# define CUB3D_PARSER_H
# include "cub3d_structs.h"
# include <stdbool.h>

/**
#=====================================#
#============ Parse_file.c ===========#
#=====================================#
*/

/**
 * @brief Validates whether a file exists and ends with .cub
 * @param file Filename to be validated
 * @return True if file exits and is a .cub file. Else returns false.
 * @note
 */
void	parse_file(char *filename, t_map *map);

void	set_map_dimensions(t_map *map);

/**
#=====================================#
#============ Parse_map.c ============#
#=====================================#
*/

/**
 * @brief Parses the lower part of the .cub file that has the map in it.
 * @param line The line to parse
 * @param map Pointer to the struct that has all the map information in it
 * @return Nothing
 * @note
 */
void	parse_map_line(char *line, t_map *map);

/**
#=====================================#
#=========== Parse_info.c ============#
#=====================================#
*/

/**
 * @brief Parses the wall textures and the floor/ceiling colors and puts it
 * in the map struct. If a line is wrong, an error is outputed.
 * @param line The line to check
 * @param map Pointer to the struct that has all the map information in it
 * @return Nothing
 * @note
 */
void	get_info_from_file(char **line, t_map *map);

/**
#=====================================#
#========== Parser_utils.c ===========#
#=====================================#
*/

/**
 * @brief Initiates the variables in the map struct
 * @param map Pointer to the struct that has all the map information in it
 * @return Nothing
 * @note
 */
void	init_map(t_map *map);

/**
 * @brief Checks whether all the textures and floor/ceiling colors have been
 * set.
 * @param map Pointer to the struct that has all the map information in it
 * @return True if all have been set. Else false.
 * @note
 */
bool	all_info_is_set(t_map *map);

/**
 * @brief fills up the empty spaces to walls for a nicer looking minimap and
 * to prevent breakouts.
*/
void	add_walls_on_empty_spaces(t_map *map_data);

void	print_map(char **map);

/**
#=====================================#
#========== validate_map.c ===========#
#=====================================#
*/

/**
 * @brief Function that checks whether the inputed map is valid.
 * @param map Pointer to the struct that has all the map information in it
 * @return Nothing
 * @note
 */
void	validate_map(t_map *map);

#endif
