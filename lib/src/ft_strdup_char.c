/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup_char.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 07:48:58 by cpost         #+#    #+#                 */
/*   Updated: 2022/08/22 07:57:19 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_strdup_char() searches for the first occurrence of 
 * the character c. It then creates and returns a new string from the 
 * position of c..
 * @param str the source string
 * @param c The character to look for
 * @return *char - new string. If characther is
 * 0, return NULL. If c isn't found, return NULL.
 * @note
 */
char	*ft_strdup_char(const char *str, char c)
{
	long	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (ft_strdup(&str[i]));
		i++;
	}
	return (NULL);
}
