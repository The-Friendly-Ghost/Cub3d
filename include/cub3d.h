/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:48:32 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/05 10:04:31 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_rgb {
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}	t_rgb;

typedef struct s_texture {
	char	*file;
}	t_texture;

typedef struct s_map {
	char		**map;
	int			n_row;
	int			n_column;
	t_texture	*north_wall;
	t_texture	*east_wall;
	t_texture	*south_wall;
	t_texture	*west_wall;
	t_rgb		*floor;
	t_rgb		*ceiling;
}	t_map;

// src/utils.c

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
