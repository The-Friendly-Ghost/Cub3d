/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:42:36 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 14:10:51 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	The memset() function fills the first n bytes of the memory area 
	pointed to by s with the constant byte c.
Input: 
	- s: pointer to the array to be copied to
	- c: The character that will be copied to the array
	- n: the amount of bytes to be copied
Return value: 
	The memset() function returns a pointer to the memory area s.
*/

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*x;

	x = s;
	while (n > 0)
	{
		*x = c;
		n--;
		x++;
	}
	return (s);
}
