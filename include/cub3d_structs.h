/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:48:32 by cpost             #+#    #+#             */
/*   Updated: 2022/12/19 13:30:29 by merel            ###   ########.fr       */
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

// okay future Merel, here is a thing... the x and y pos of the player
// should probably be floats, but the x and y position of the map[][] should
// probably be ints, so maybe create another vector2d?
typedef struct s_fVector2d {
	float			x;
	float			y;
}	t_fVector2d;

typedef struct s_Vector2d {
	int			x;
	int			y;
}	t_Vector2d;

/**
 * @param position a 2d vector with an x and y position
 * @param turnDirection -1 if turned left +1 if turned right
 * @param walkDirection -1 if back, +1 if front
 * @param cameraPlane?
 * @param MoveSpeed	How many pixels the character can move since the last frame
 * (maybe make it time dependent)
 * @param rotationSpeed How fast the camera can turn left and right
*/
typedef struct s_player{
	t_fVector2d	position;
	int			turnDirection;
	int			walkDirection;
	t_Vector2d	cameraPlane;
	float		rotationAngle;
	int			moveSpeed;
	int			rotationSpeed;
}	t_player;

typedef struct s_images{
	mlx_image_t	*floor;
	mlx_image_t	*ceiling;
	mlx_image_t	*walls;
}	t_images;

typedef struct s_cub3d {
	mlx_t		*mlx;
	int			windowWidth;
	int			windowHeight;
	t_map		map_data;
	t_player	player_data;
	double		last_time;
	t_images	images;
}	t_cub3d;

#endif
