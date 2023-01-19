/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:58:25 by cpost         #+#    #+#                 */
/*   Updated: 2023/01/19 11:43:36 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include "cub3d_utils.h"
#include "cub3d_structs.h"
#include "libft.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include "cub3d_render.h"
#include "cub3d_init.h"

void	free_map_data(t_map *map_data)
{
	int	i;

	i = 0;
	while (map_data->map[i])
	{
		free (map_data->map[i]);
		i++;
	}
	free (map_data->map);
	free (map_data->ceiling);
	free (map_data->floor);
}

static void	check_constants(void)
{
	if (MINI_SCALE < 0.1 || MINI_SCALE > 1)
		exit_error("Minimap factor must be between 0.1 and 1", 1);
	if (WINDOW_HEIGHT < 100 || WINDOW_HEIGHT > 1500)
		exit_error("Window height must be between 100 and 1500", 1);
	if (WINDOW_WIDTH < 200 || WINDOW_WIDTH > 2000)
		exit_error("Window width must be between 200 and 2000", 1);
	if (WINDOW_WIDTH / WINDOW_HEIGHT < 1 || WINDOW_WIDTH / WINDOW_HEIGHT > 2)
		exit_error("Window aspect ratio must be between 1:1 and 2:1", 1);
	if (FOV_ANGLE != 60)
		exit_error("FOV Angle must be 60", 1);
	if (WALL_STRIP_WIDTH != 1)
		exit_error("Wall strip width must be 1", 1);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d_data;

	atexit(done);
	if (argc != 2)
		exit_error("Invalid amount of arguments", 1);
	check_constants();
	init_map(&cub3d_data.map_data);
	parse_file(argv[1], &cub3d_data.map_data);
	validate_map(&cub3d_data.map_data);
	close(cub3d_data.map_data.fd_map);
	init_player_vars(&cub3d_data.player_data, cub3d_data.map_data.map);
	cub3d_data.fov = (FOV_ANGLE * (M_PI / 180));
	cub3d_data.distance_to_plane = (WINDOW_WIDTH / 2) / tan(cub3d_data.fov / 2);
	cub3d_data.num_rays = (WINDOW_WIDTH / WALL_STRIP_WIDTH);
	cub3d_data.rays = NULL;
	init_mlx(&cub3d_data);
	free_map_data(&cub3d_data.map_data);
	return (0);
}
