/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:42:26 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 13:59:31 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	The memchr() function scans the initial n bytes of the memory
	area pointed to by s for the first instance of c.
Input: 
	- s: the pointer to an array
	- c: the character to search for
	- n: the initial amount of bytes to be searched
Return value: 
	The memchr() and memrchr() functions return a pointer to the 
	matching byte or NULL if the character does not occur in the 
	given memory area.
*/

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		t;
	size_t				i;
	const unsigned char	*x;

	i = 0;
	x = s;
	t = c;
	while (i < n)
	{
		if (x[i] == t)
			return ((void *)&x[i]);
		i++;
	}
	return (0);
}
