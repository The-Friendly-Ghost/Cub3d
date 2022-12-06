/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:58:25 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/06 16:07:37 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include "cub3d_utils.h"
#include "cub3d_structs.h"
#include "libft.h"
#include <stdbool.h>
#include <unistd.h>
//
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map	map;

	(void)argv;
	if (argc != 2)
		exit_error("Invalid amount of arguments", 1);
	init_map(&map);
	parse_file(argv[1], &map);
	close(map.fd_map);
	return (1);
}
