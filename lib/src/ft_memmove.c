/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:42:33 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 14:06:59 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	The memmove() function copies n bytes from memory area src to 
	memory area dest.  The memory areas may overlap: copying takes 
	place as though the bytes in src are first copied into a 
	temporary array that does not overlap src or dest, and the bytes 
	are then copied from the temporary array to dest.
Input: 
	- src: pointer to the array that will be copied
	- dest: pointer to the array to be copied to
	- n: the amount of bytes to be copied
Return value: 
	The memcpy() function returns a pointer to dest.
*/

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	if (src > dest)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	return (dest);
}
