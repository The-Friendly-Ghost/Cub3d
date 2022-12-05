/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:08 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 14:34:33 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	Allocates (with malloc(3)) and returns a new 
	string, which is the result of the concatenation 
	of ’s1’ and ’s2’.
Input: 
	- s: The prefix string.
	- f: The suffix string.
Return value: 
	The new string. NULL if the allocation fails.
*/

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	size_s1;
	unsigned int	size_s2;
	char			*str;

	if (!s1 || !s2)
		return (0);
	size_s1 = ft_strlen((char *)s1);
	size_s2 = ft_strlen((char *)s2);
	str = malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_memcpy(str, s1, size_s1);
	ft_memcpy(str + size_s1, s2, size_s2);
	str[size_s1 + size_s2] = 0;
	return (str);
}
