/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup_after.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 07:40:57 by cpost         #+#    #+#                 */
/*   Updated: 2022/08/22 07:45:43 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_strdup_after() searches for the first occurrence of 
 * the character c. It then creates and returns a new string from the 
 * position of c + 1.
 * @param str the source string
 * @param c The character to look for
 * @return *char - new string. If characther is
 * 0, return NULL. If c isn't found, return NULL.
 * @note
 */
char	*ft_strdup_after(const char *str, char c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return (ft_strdup(&str[i + 1]));
		i++;
	}
	return (NULL);
}
