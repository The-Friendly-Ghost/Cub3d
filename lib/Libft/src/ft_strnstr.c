/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:25 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 15:27:00 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	The strnstr() function locates the first occurrence of the 
	null-terminated string little in the string big, where not 
	more than len charactersare searched. Characters that appear 
	after a `\0' character are not searched.
Input: 
	- big: the larger string
	- little: the 'haystack' to be found in the big string
	- len: amount of bytes to search inside of big
Return value: 
	If little is an empty string, big is returned; if little occurs 
	nowhere in big, NULL is returned; otherwise a pointer to the first 
	character of the first occurrence of little is returned.
*/

#include <stddef.h>

static int	ft_scan(const char *big, const char *little, size_t i, size_t n)
{
	int	x;

	x = 0;
	while (little[x] != '\0')
	{
		if (i >= n)
			return (2);
		else if (little[x] == big[i])
		{
			i++;
			x++;
		}
		else if (little[x] != big[i])
			return (0);
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;

	i = 0;
	if (little[0] == '\0')
		return ((char *)&big[i]);
	if (len == 0)
		return (0);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			if (ft_scan(big, little, i, len) == 2)
				return (0);
			if (ft_scan(big, little, i, len) == 1)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
