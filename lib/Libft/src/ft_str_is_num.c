/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_is_num.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 15:04:48 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/06 15:09:07 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a string contains only numbers
 * @param num The string to check
 * @return 1 if string contains only numbers. Else 0.
 * @note
 */
int	ft_str_is_num(char *num)
{
	int	i;

	i = 0;
	if (num == NULL)
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}
