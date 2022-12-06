/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 14:15:04 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/06 18:05:35 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include "cub3d_structs.h"
#include <stdbool.h>
#include <stddef.h>
#include "libft.h"

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

// TODO Deze functie kan later verwijderd worden als map parsing 100% goed gaat
void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr_fd(map[i], 1);
		i++;
	}
}
