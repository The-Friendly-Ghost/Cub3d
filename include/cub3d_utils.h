/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_utils.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 11:13:37 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/05 13:17:04 by cpost         ########   odam.nl         */
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

#endif
