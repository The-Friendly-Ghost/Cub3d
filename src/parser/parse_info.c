/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_info.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 16:09:45 by cpost         #+#    #+#                 */
/*   Updated: 2023/01/31 13:13:46 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include "cub3d_structs.h"
#include "cub3d_utils.h"
#include "MLX42/MLX42.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void	*null_check_texture(mlx_texture_t *pointer, char *line)
{
	if (pointer != NULL)
		exit_error ("Invalid .cub file", 1);
	return (alloc_check(mlx_load_png(line)));
}

static t_rgb	*get_rgb(t_rgb *pointer, char **line)
{
	t_rgb	*rgb;

	if (pointer != NULL)
		exit_error ("Invalid .cub file", 1);
	rgb = alloc_check(malloc(sizeof(t_rgb)));
	if (!ft_str_is_num(line[1]) || !ft_str_is_num(line[2])
		|| !ft_str_is_num(line[3]) || line[4])
		exit_error("RGB values not valid [0 - 255]", 1);
	rgb->red = ft_atoi(line[1]);
	rgb->green = ft_atoi(line[2]);
	rgb->blue = ft_atoi(line[3]);
	if (rgb->blue < 0 || rgb->blue > 255 || rgb->red < 0 || rgb->red > 255
		|| rgb->green < 0 || rgb->green > 255)
		exit_error("RGB values not valid [0 - 255]", 1);
	return (rgb);
}

void	get_info_from_file(char **line, t_map *map)
{
	if (line[0] == NULL)
		return (free(line));
	if (!ft_strcmp(line[0], "SO") && line[1] && !line[2])
		map->south_wall = null_check_texture(map->south_wall, line[1]);
	else if (!ft_strcmp(line[0], "NO") && line[1] && !line[2])
		map->north_wall = null_check_texture(map->north_wall, line[1]);
	else if (!ft_strcmp(line[0], "WE") && line[1] && !line[2])
		map->west_wall = null_check_texture(map->west_wall, line[1]);
	else if (!ft_strcmp(line[0], "EA") && line[1] && !line[2])
		map->east_wall = null_check_texture(map->east_wall, line[1]);
	else if (!ft_strcmp(line[0], "F") && line[1])
		map->floor = get_rgb(map->floor, line);
	else if (!ft_strcmp(line[0], "C") && line[1])
		map->ceiling = get_rgb(map->ceiling, line);
	else
		exit_error ("Invalid .cub file", 1);
	ft_free_double_arr(line);
}
