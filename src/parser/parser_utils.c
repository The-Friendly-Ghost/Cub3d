/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 14:15:04 by cpost         #+#    #+#                 */
/*   Updated: 2023/01/19 13:50:51 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include "cub3d_structs.h"
#include <stdbool.h>
#include <stddef.h>
#include "libft.h"

void	init_map(t_map *map)
{
	map->ceiling = NULL;
	map->map = NULL;
	map->floor = NULL;
	map->east_wall = NULL;
	map->north_wall = NULL;
	map->south_wall = NULL;
	map->west_wall = NULL;
	map->n_column = 0;
	map->n_row = 0;
}

bool	all_info_is_set(t_map *map)
{
	if (map->ceiling == NULL)
		return (false);
	if (map->floor == NULL)
		return (false);
	if (map->east_wall == NULL)
		return (false);
	if (map->west_wall == NULL)
		return (false);
	if (map->north_wall == NULL)
		return (false);
	if (map->south_wall == NULL)
		return (false);
	return (true);
}

void	add_walls_on_empty_spaces(t_map *map_data)
{
	int	y;
	int	x;

	y = 0;
	while (map_data->map[y])
	{
		x = 0;
		while (map_data->map[y][x])
		{
			if (map_data->map[y][x] == ' ' || map_data->map[y][x] == '\n')
				map_data->map[y][x] = '1';
			x++;
		}
		y++;
	}
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr_fd(map[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}
