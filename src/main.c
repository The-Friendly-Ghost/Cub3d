/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:58:25 by cpost             #+#    #+#             */
/*   Updated: 2022/12/13 11:59:50 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include "cub3d_utils.h"
#include "cub3d_structs.h"
#include "libft.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include "cub3d_render.h"
#include "cub3d_init.h"



int	main(int argc, char **argv)
{
	t_cub3d	cub3d_data;

	if (argc != 2)
		exit_error("Invalid amount of arguments", 1); 
	init_map(&cub3d_data.map_data);
	parse_file(argv[1], &cub3d_data.map_data);
	validate_map(&cub3d_data.map_data);
	init_player_vars(&cub3d_data.player_data, cub3d_data.map_data.map);
	close(cub3d_data.map_data.fd_map);
	init_mlx(&cub3d_data);
	return (0);
}
