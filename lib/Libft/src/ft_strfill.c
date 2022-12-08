/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strfill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 16:34:20 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/08 10:44:01 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief If str is shorter then len: a new string is malloced with length 
 * 'len'. The old content is then copied to the new string. The space left
 * will then be filled up with char 'c'.
 * @param str The string to fill with char c
 * @param len The minimum length the new string has to be
 * @param c The fill-character
 * @return pointer to the newly created string. Or pointer to the old string if
 * the length of the old string >= len.
 * @note
 */
char	*ft_strfill(char *str, size_t len, char c)
{
	char		*new_str;
	size_t		i;

	i = 0;
	if (str == NULL || len == 0)
		return (NULL);
	if (ft_strlen(str) >= len)
		return (str);
	new_str = malloc((len + 1) * sizeof(char));
	while (str && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (i < len)
	{
		new_str[i] = c;
		i++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}
