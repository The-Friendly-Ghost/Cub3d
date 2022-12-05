/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup_before.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 07:42:59 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/05 09:11:34 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_strdup_before() function finds the first occurrence of char
 * c. It then creates a new string and copies up to char c to this new string
 * and puts a \0 after it. Note, char C is not copied. if c is \0, return a
 * copy of str. If c isn't found, return NULL;
 * @param str the source string
 * @param c The character to look for
 * @return *char - a new string copied up to char c. If characther is
 * 0, return the end of the string.
 * @note
 */
char	*ft_strdup_before(const char *str, char c)
{
	int		i;
	char	*new_str;

	i = 0;
	if (c == '\0')
		return (ft_strdup(str));
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	new_str = ft_calloc(sizeof(char), i + 1);
	ft_strlcpy(new_str, str, i + 1);
	return (new_str);
}
