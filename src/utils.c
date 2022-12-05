/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 09:15:12 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/05 09:18:00 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	exit_error(char *message, int exit_code)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	exit(exit_code);
}
