/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_structs.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:48:32 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/06 15:13:03 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H
# include "MLX42/MLX42.h"

/**
#=====================================#
#============== Structs ==============#
#=====================================#
*/

typedef struct s_rgb {
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_map {
	char				**map;
	int					fd_map;
	int					n_row;
	int					n_column;
	struct mlx_texture	*north_wall;
	struct mlx_texture	*east_wall;
	struct mlx_texture	*south_wall;
	struct mlx_texture	*west_wall;
	t_rgb				*floor;
	t_rgb				*ceiling;
}	t_map;

#endif
