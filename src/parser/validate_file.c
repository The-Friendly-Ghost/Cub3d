/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_file.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 10:31:54 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/05 13:34:44 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include "cub3d_structs.h"
#include "cub3d_utils.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

void	parse_map(t_map *map)
{
	char	*line_read;

	(void)map;
	// while (line_read != NULL)
	// {
	// 	line_read = get_next_line(map->fd_map);
		
	// }
}

void	validate_filetype(char *file, t_map *map)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (i < 5)
		exit_error("Invalid filename", 1);
	if (file [i - 1] != 'b' || file [i - 2] != 'u' || file [i - 3] != 'c'
		|| file [i - 4] != '.')
		exit_error("Invalid filename", 1);
	map->fd_map = open(file, R_OK);
	if (map->fd_map < 0)
		exit_error(strerror(errno), 1);
	parse_map(map);
}
