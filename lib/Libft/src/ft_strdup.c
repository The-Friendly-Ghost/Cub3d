/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:02 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 14:32:11 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	The strdup() function returns a pointer to a new string which is 
	a duplicate of the string s.  Memory for the new string is 
	obtained with malloc(3), and can be freed with free(3).
Input: 
	- s: The string to copy.
Return value: 
	On success, the strdup() function returns a pointer to the 
	duplicated string.  It returns NULL if insufficient memory was 
	available.
*/

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*x;
	int		i;

	i = 0;
	x = malloc(ft_strlen((char *)s) + 1);
	if (!x)
		return (0);
	while (s[i])
	{
		x[i] = s[i];
		i++;
	}
	x[i] = 0;
	return (x);
}
