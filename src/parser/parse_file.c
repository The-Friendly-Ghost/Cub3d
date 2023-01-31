/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_file.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 10:31:54 by cpost         #+#    #+#                 */
/*   Updated: 2023/01/31 12:39:22 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include "cub3d_structs.h"
#include "cub3d_utils.h"
#include "get_next_line.h"
#include "MLX42/MLX42.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

static void	read_file(t_map *map)
{
	char	*line_read;

	line_read = get_next_line(map->fd_map);
	if (line_read == NULL)
		exit_error(".cub file is empty", 1);
	while (line_read != NULL)
	{
		if (all_info_is_set(map) == false)
			get_info_from_file(alloc_check(ft_split_set(line_read,
						",\t\v\f\r\n ")), map);
		else
			parse_map_line(line_read, map);
		free(line_read);
		line_read = get_next_line(map->fd_map);
		if (line_read == NULL && all_info_is_set(map) == false)
			exit_error("Invalid input in .cub file, or failed to load png", 1);
	}
	if (!map->map)
		exit_error("No map in .cub file, or map is in wrong place", 1);
}

static void	init_map_textures(t_map *map)
{
	map->ceiling = NULL;
	map->floor = NULL;
	map->east_wall = NULL;
	map->north_wall = NULL;
	map->south_wall = NULL;
	map->west_wall = NULL;
}

void	parse_file(char *filename, t_map *map)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (i < 5)
		exit_error("Invalid filename", 1);
	if (filename [i - 1] != 'b' || filename [i - 2] != 'u'
		|| filename [i - 3] != 'c' || filename [i - 4] != '.')
		exit_error("Invalid filename", 1);
	map->fd_map = open(filename, R_OK);
	if (map->fd_map < 0)
		exit_error(strerror(errno), 1);
	init_map_textures(map);
	read_file(map);
}
