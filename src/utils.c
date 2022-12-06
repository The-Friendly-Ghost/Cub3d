/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 09:15:12 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/06 12:54:18 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_parser.h"
#include "cub3d_utils.h"
#include <stdlib.h>

void	*alloc_check(void *ptr)
{
	if (!ptr)
		exit_error("Malloc fail\n", 1);
	return (ptr);
}

void	exit_error(char *message, int exit_code)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	exit(exit_code);
}
