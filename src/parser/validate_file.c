/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_file.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 10:31:54 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/05 16:57:54 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include "cub3d_structs.h"
#include "cub3d_utils.h"
#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#include <stdio.h>

char	*get_rgb(char *line)
{
	t_rgb		*rgb;
	int			i;
	int			color;

	rgb = malloc(sizeof(t_rgb));
	i = 0;
	while (line[i] && ft_is_whitespace(line[i]))
		i++;
	while (line[i] && ft_isdigit(line[i]))
	{
		color = (color * 10) + line[i];
		i++;
	}
	path = ft_calloc((len + 1), sizeof(char));
	ft_strlcpy(path, line + temp, len + 1);
	return (path);
}

char	*get_path(char *line)
{
	char	*path;
	int		i;
	int		len;
	int		temp;

	i = 0;
	len = 0;
	while (line[i] && ft_is_whitespace(line[i]))
		i++;
	temp = i;
	while (line[i] && !ft_is_whitespace(line[i]))
	{
		len++;
		i++;
	}
	path = ft_calloc((len + 1), sizeof(char));
	ft_strlcpy(path, line + temp, len + 1);
	return (path);
}

void	get_info_from_file(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] && ft_is_whitespace(line[i]))
		i++;
	if (!ft_strncmp(line + i, "SO ", 3))
		map->south_wall = get_path(line + i + 3);
	else if (!ft_strncmp(line + i, "NO ", 3))
		map->north_wall = get_path(line + i + 3);
	else if (!ft_strncmp(line + i, "WE ", 3))
		map->west_wall = get_path(line + i + 3);
	else if (!ft_strncmp(line + i, "EA ", 3))
		map->east_wall = get_path(line + i + 3);
	else if (!ft_strncmp(line + i, "F ", 2))
		map->floor = get_rgb(line + i + 2);
	else if (!ft_strncmp(line + i, "C ", 2))
		map->south_wall = get_rgb(line + i + 2);
}

void	parse_map(t_map *map)
{
	char	*line_read;

	line_read = get_next_line(map->fd_map);
	if (line_read == NULL)
		exit_error(".cub file is empty", 1);
	while (line_read != NULL)
	{
		if (all_info_is_set(map) == false)
			get_info_from_file(line_read, map);
		// else
		// 	parse_map(line_read, map);
		free(line_read);
		line_read = get_next_line(map->fd_map);
	}
}

void	validate_filetype(char *filename, t_map *map)
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
	parse_map(map);
}
