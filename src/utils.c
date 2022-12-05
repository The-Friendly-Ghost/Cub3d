/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 09:15:12 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/05 13:47:39 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_parser.h"
#include <stdlib.h>

void	exit_error(char *message, int exit_code)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	exit(exit_code);
}
