/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 16:05:42 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/07 17:00:13 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include "cub3d_structs.h"
#include "cub3d_utils.h"
#include "libft.h"
#include <stdlib.h>

#include <stdio.h> //TODO weghalen

char	*trim_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	return (str);
}

int	str_is_whitespace(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_is_whitespace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	allocate_more_space(t_map *map, unsigned int *capacity)
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

void	parse_map_line(char *line, t_map *map)
{
	static unsigned int	capacity;
	static unsigned int	map_row;
	static unsigned int	map_init_started;

	if (str_is_whitespace(line) && map_init_started == 0)
		return ;
	if (map->map == NULL)
	{
		capacity = 4;
		map->map = malloc(sizeof(char *) * capacity); // TODO Deze protecten
	}
	if (capacity == 1)
		allocate_more_space(map, &capacity);
	map->map[map_row] = ft_strdup(line); // TODO Strdup protect als line NULL is ?
	map->map[map_row] = trim_newline(map->map[map_row]);
	map_row++;
	map->map[map_row] = NULL;
	map_init_started = 1;
	capacity--;
}
