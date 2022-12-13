/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:48:32 by cpost             #+#    #+#             */
/*   Updated: 2022/12/13 11:30:05 by merel            ###   ########.fr       */
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

typedef struct s_Vector2d {
	int			x;
	int			y;
}	t_Vector2d;

typedef struct s_player{
	t_Vector2d	position;
	t_Vector2d	direction;
	t_Vector2d	cameraPlane;
}	t_player;

typedef struct s_images{
	mlx_image_t	*floor;
	mlx_image_t	*ceiling;
	mlx_image_t	*walls;
}	t_images;

typedef struct s_cub3d {
	mlx_t		*mlx;
	t_map		map_data;
	t_player	player_data;
	double		last_time;
	t_images	imgages;
}	t_cub3d;

#endif
