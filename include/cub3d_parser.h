/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_parser.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 11:13:37 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/05 15:48:53 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSER_H
# define CUB3D_PARSER_H
# include "cub3d_structs.h"
# include <stdbool.h>

/**
#=====================================#
#============= Functions =============#
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
 * @brief Parses the wall textures and the floor/ceiling colors and puts it
 * in the map struct. If a line is wrong, an error is outputed.
 * @param line The line to check
 * @param map Pointer to the struct that has all the map information in it
 * @return Nothing
 * @note
 */
void	get_info_from_file(char *line, t_map *map);

/**
 * @brief Checks if a line qualifies as part of the map or not.
 * @param line The line to check
 * @return True if a line is part of the map, false if this is not the case.
 * @note
 */
bool	is_map(char *line);

/**
 * @brief Checks if a character is a whitespace
 * @param c The character to check
 * @return 1 if c is whitespace. 0 if c is not whitespace.
 * @note
 */
bool	ft_is_whitespace(char c);

/**
 * @brief Parse the line that get_next_line just read. Check whether it's a
 * wall structure, floor/ceiling color or line of the map.
 * @param map Pointer to the struct that has all the map information in it
 * @return Nothing
 * @note
 */
void	parse_line_read(char *line, t_map *map);

/**
 * @brief Function that calls get_next_line to read the map line by line.
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
