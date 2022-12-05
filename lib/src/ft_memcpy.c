/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:42:31 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 14:06:10 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	The memcpy() function copies n bytes from memory area src to 
	memory area dest.  The memory areas must not overlap.  Use 
	memmove(3) if the memory areas do overlap.
Input: 
	- src: pointer to the array that will be copied
	- dest: pointer to the array to be copied to
	- n: the amount of bytes to be copied
Return value: 
	The memcpy() function returns a pointer to dest.
*/

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
