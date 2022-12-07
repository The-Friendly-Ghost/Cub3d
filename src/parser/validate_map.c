/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 12:33:22 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/07 17:28:24 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include "cub3d_structs.h"
#include "cub3d_utils.h"
#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static void	check_if_map_is_closed(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '0')
			{
				if (x == 0 || y == 0 || map->map[y + 1] == NULL
					|| map->map[y][x + 1] == '\n' || map->map[y][x + 1] == '\0')
					exit_error("Map not enclosed by walls", 1);
				if (map->map[y - 1][x] == ' ' || map->map[y + 1][x] == ' '
					|| map->map[y][x - 1] == ' ' || map->map[y][x + 1] == ' ')
					exit_error("Map not enclosed by walls", 1);
			}
			x++;
		}
		y++;
	}
}

/**
 * @brief Equalizes all rows to the same length.
 * @param map Pointer to the struct that has all the map information in it
 * @return Nothing
 * @note
 */
static void	equalize_row_length(t_map *map)
{
	unsigned long	len;
	int				i;

	i = 0;
	len = 0;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) > len)
			len = ft_strlen(map->map[i]);
		i++;
	}
	i = 0;
	while (map->map[i])
	{
		map->map[i] = ft_strfill(map->map[i], len, ' ');
		i++;
	}
}

static void	check_forbidden_characters_in_map(t_map *map)
{
	bool	player_init;
	int		y;
	int		x;

	player_init = false;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'N' || map->map[y][x] == 'S'
				|| map->map[y][x] == 'W' || map->map[y][x] == 'E')
			{
				if (player_init == true)
					exit_error("Only 1 player allowed in map", 1);
				player_init = true;
			}
			else if (map->map[y][x] != '1' && map->map[y][x] != '0'
				&& map->map[y][x] != ' ')
				exit_error("Forbidden characters in map", 1);
			x++;
		}
		y++;
	}
}

/**
 * @brief First, removes all the lines that contain only whitespaces off the 
 * bottom of the map. Then, checks if there is a line with only whitespaces
 * somewhere inside of the map. If that is the case, the program exits.
 * @param map Pointer to the struct that has all the map information in it
 * @return Nothing
 * @note
 */
static void	check_empty_lines(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
		i++;
	i--;
	while (str_is_whitespace(map->map[i]))
	{
		free(map->map[i]);
		map->map[i] = NULL;
		i--;
	}
	i = 0;
	while (map->map[i])
	{
		if (str_is_whitespace(map->map[i]))
			exit_error("No empty lines inside of the map allowed", 1);
		i++;
	}
}

void	validate_map(t_map *map)
{
	check_empty_lines(map);
	equalize_row_length(map);
	check_forbidden_characters_in_map(map);
	check_if_map_is_closed(map);
print_map(map->map);
}
