/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_is_whitespace.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 10:36:51 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/08 10:38:58 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if an entire string contains whitespaces
 * @param str The string to check
 * @return 1 if the entire string is whitespace. 0 if the string contains an
 * other character.
 * @note
 */
int	ft_str_is_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_whitespace(str[i]))
			return (0);
		i++;
	}
	return (1);
}
