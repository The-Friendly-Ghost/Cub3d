/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_structs.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:48:32 by cpost         #+#    #+#                 */
/*   Updated: 2023/01/19 11:23:36 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H
# include "MLX42/MLX42.h"
# include "cub3d_enums.h"

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

typedef struct s_fVector2d {
	float			x;
	float			y;
}	t_fVector2d;

typedef struct s_Vector2d {
	int			x;
	int			y;
}	t_Vector2d;

typedef struct s_player{
	t_fVector2d	position;
	float		turn_direction;
	int			walk_direction;
	int			strafe_direction;
	double		rotation_angle;
	int			move_speed;
	float		rotation_speed;
}	t_player;

typedef struct s_images{
	mlx_image_t	*floor;
	mlx_image_t	*ceiling;
	mlx_image_t	*walls;
	mlx_image_t	*mini_map;
	mlx_image_t	*rays;
}	t_images;

typedef struct s_ray {
	double		ray_angle;
	t_fVector2d	horizontal_step;
	t_fVector2d	horizontal_wall_hit;
	t_fVector2d	vertical_step;
	t_fVector2d	vertical_wall_hit;
	float		distance;
	bool		was_hit_vertical;
	bool		was_hit_horizontal;
	bool		is_ray_facing_up;
	bool		is_ray_facing_right;
	t_direction	hit_wall_direction;
	float		wall_height;
	int			draw_start;
	int			draw_end;
}			t_ray;

typedef struct s_cub3d {
	mlx_t		*mlx;
	float		fov;
	float		num_rays;
	float		distance_to_plane;
	t_map		map_data;
	t_player	player_data;
	double		last_time;
	t_images	images;
	t_ray		*rays;
}	t_cub3d;

#endif
