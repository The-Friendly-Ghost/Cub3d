/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 14:15:04 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/05 15:49:40 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include <stdbool.h>
#include <stddef.h>

/**
 * @note TODO Not sure of die if-statement later aangepast moet worden.
 * Misschien covered deze statement niet alle edge cases.
 */
bool	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (ft_is_whitespace(line[i]))
			i++;
		if (line[i] == '1' || line[i] == '0')
			return (true);
		else
			return (false);
	}
	return (false);
}

bool	ft_is_whitespace(char c)
{
	if (c == ' ')
		return (true);
	if (c == '\t')
		return (true);
	if (c == '\n')
		return (true);
	if (c == '\v')
		return (true);
	if (c == '\f')
		return (true);
	if (c == '\r')
		return (true);
	return (false);
}

void	init_map(t_map *map)
{
	map->ceiling = NULL;
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
