/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_structs.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:48:32 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/05 11:35:44 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

/**
#=====================================#
#============== Structs ==============#
#=====================================#
*/

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
	int			fd_map;
	int			n_row;
	int			n_column;
	t_texture	*north_wall;
	t_texture	*east_wall;
	t_texture	*south_wall;
	t_texture	*west_wall;
	t_rgb		*floor;
	t_rgb		*ceiling;
}	t_map;

#endif
