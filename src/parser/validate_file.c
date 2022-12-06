/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_file.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 10:31:54 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/06 14:16:47 by cpost         ########   odam.nl         */
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

// void	line_to_map(t_map *map, char *line, unsigned int map_row)
// {
// 	map->map[map_row] = ft_strdup(line);
// }

void	allocate_more_space(t_map *map, unsigned int *capacity)
{
	static unsigned int	new_size;
	char				**new_map;
	int					i;

	if (new_size == 0)
		new_size = 8;
	i = 0;
	while (map->map[i])
		i++;
	new_map = malloc(sizeof(char *) * new_size); //TODO Protect! //Moet deze niet met NULL gevuld worden?
	while (i > 0)
	{
		i--;
		new_map[i] = ft_strdup(map->map[i]);
		free(map->map[i]);
	}
	free(map->map);
	map->map = new_map;
	*capacity = new_size / 2;
	new_size *= 2;
}

void	parse_map(char *line, t_map *map)
{
	static unsigned int	capacity;
	static unsigned int	map_row;

	if (map->map == NULL)
	{
		capacity = 4;
		map->map = malloc(sizeof(char *) * capacity); // TODO Deze protecten
	}
	if (capacity == 1)
		allocate_more_space(map, &capacity);
	map->map[map_row++] = ft_strdup(line); // TODO Strdup protect als line NULL is ?
	map->map[map_row] = NULL;
	capacity--;
}

t_rgb	*get_rgb(char **line)
{
	t_rgb	*rgb;
	char	**rgb_values;

	rgb = malloc(sizeof(t_rgb));
	rgb_values = ft_split(line[1], ',');
	rgb->red = ft_atoi(rgb_values[0]);
	rgb->green = ft_atoi(rgb_values[1]);
	rgb->blue = ft_atoi(rgb_values[2]);
	// TODO rgb_values freeen!'
	// TODO ATOI returned 0 als het verkerd gaat dat moet anders, 
	// 0 is een rgb value.
	return (rgb);
}

// TODO error check toevoegen als mlx_load_png verkeerd gaat.
// TODO als er een newline direct achter de filename staat, werkt het niet.
void	get_info_from_file(char **line, t_map *map)
{
	if (!ft_strcmp(line[0], "SO"))
		map->south_wall = mlx_load_png(line[1]);
	else if (!ft_strcmp(line[0], "NO"))
		map->north_wall = mlx_load_png(line[1]);
	else if (!ft_strcmp(line[0], "WE"))
		map->west_wall = mlx_load_png(line[1]);
	else if (!ft_strcmp(line[0], "EA"))
		map->east_wall = mlx_load_png(line[1]);
	else if (!ft_strcmp(line[0], "F"))
		map->floor = get_rgb(line);
	else if (!ft_strcmp(line[0], "C"))
		map->ceiling = get_rgb(line);
}

void	parse_file(t_map *map)
{
	char	*line_read;
	char	**line_split;

	line_read = get_next_line(map->fd_map);
	if (line_read == NULL)
		exit_error(".cub file is empty", 1);
	while (line_read != NULL)
	{
		line_split = ft_split(line_read, ' ');
		if (all_info_is_set(map) == false)
			get_info_from_file(line_split, map);
		else
			parse_map(line_read, map);
		free(line_read);
		// TODO Line split volledig freeen.
		line_read = get_next_line(map->fd_map);
	}
}

void	print_map(char **map)
{
	int	i;
	
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
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
	parse_file(map);
	// print_map(map->map);
}
