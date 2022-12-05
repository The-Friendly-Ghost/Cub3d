/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:34 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 15:32:21 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	Allocates (with malloc(3)) and returns a substring from the string ’s’. The 
	substring begins at index ’start’ and is of maximum size ’len’.
Input: 
	- s: The string from which to create the substring. start: The start 
	index of the substring in the string ’s’.
	- len: The maximum length of the substring.
Return value: 
	The substring. NULL if the allocation fails.
*/

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*x;
	unsigned int	i;

	if (!s)
		return (0);
	i = ft_strlen((char *)s);
	if (!len || start >= i)
		return (ft_strdup(""));
	if (len < i - start)
		x = malloc((len + 1) * sizeof(char));
	else
		x = malloc(((i - start) + 1) * sizeof(char));
	if (!x)
		return (0);
	ft_strlcpy(x, s + start, len + 1);
	return (x);
}
