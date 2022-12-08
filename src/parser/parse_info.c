/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_info.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 16:09:45 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/08 10:27:39 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include "cub3d_structs.h"
#include "cub3d_utils.h"
#include "MLX42/MLX42.h"
#include "libft.h"
#include <stdlib.h>

static t_rgb	*get_rgb(char **line)
{
	t_rgb	*rgb;

	rgb = malloc(sizeof(t_rgb));
	if (!ft_str_is_num(line[1]) || !ft_str_is_num(line[2])
		|| !ft_str_is_num(line[3]) || line[4])
		exit_error("RGB values not valid [0 - 255]", 1); // TODO freeen?
	rgb->red = ft_atoi(line[1]);
	rgb->green = ft_atoi(line[2]);
	rgb->blue = ft_atoi(line[3]);
	if (rgb->blue < 0 || rgb->blue > 255 || rgb->red < 0 || rgb->red > 255
		|| rgb->green < 0 || rgb->green > 255)
		exit_error("RGB values not valid [0 - 255]", 1);
	// TODO rgb_values freeen!'
	// TODO ATOI returned 0 als het verkerd gaat dat moet anders, 
	// 0 is een rgb value.
	return (rgb);
}

// TODO error check toevoegen als mlx_load_png verkeerd gaat.
// TODO als er een newline direct achter de filename staat, werkt het niet.
void	get_info_from_file(char **line, t_map *map)
{
	if (line[0] == NULL)
		return ;
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
	if (line)
		free(line);
}
