/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr_replace.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 10:29:30 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/08 10:43:17 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Loops over a string and replaces all instances of char 'old' with
 * char 'new'.
 * @param str The string to check
 * @param old The character to replace
 * @param new The character to replace old with
 * @return The address of str (with the new characters in it)
 * @note
 */
char	*ft_strchr_replace(char *str, char old, char new)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == old)
			str[i] = new;
		i++;
	}
	return (str);
}
