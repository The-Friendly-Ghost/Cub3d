/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_utils.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 11:13:37 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/06 11:28:55 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_UTILS_H
# define CUB3D_UTILS_H

/**
#=====================================#
#============= Functions =============#
#=====================================#
*/

/**
 * @brief Function that exits the program. But before it does that, it prints
 * "Error" followed by an error message.
 * @param message The error message to be printed
 * @param exit_code The exit code that the program has to be exited with
 * @return Nothing
 * @note
 */
void	exit_error(char *message, int exit_code);

/**
 * @brief Function that can be used to protect memory allocation.
 * Will exit the program if the pointer is NULL.
 * @param ptr a pointer to the allocated memory
 * @returns the allocated pointer if it's not null
 * @note example: str = alloc_check(malloc(sizeof(char) * 10))
 */
void	*alloc_check(void *ptr);

#endif
