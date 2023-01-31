/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 09:15:12 by cpost         #+#    #+#                 */
/*   Updated: 2023/01/31 13:16:39 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_parser.h"
#include "cub3d_utils.h"
#include <stdlib.h>
#include "cub3d_render.h"
#include "math.h"

void	*alloc_check(void *ptr)
{
	if (!ptr)
		exit_error("NULL pointer received", 1);
	return (ptr);
}

void	exit_error(char *message, int exit_code)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	exit(exit_code);
}
