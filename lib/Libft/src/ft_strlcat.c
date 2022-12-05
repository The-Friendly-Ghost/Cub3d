/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:11 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 15:06:00 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	The strlcat() function concatenates strings. The strlcat() 
	function appends the NUL-terminated string src to the end of dst. 
	It will append at most size - strlen(dst) - 1 bytes, NUL-terminating 
	the result.
Input: 
	- src: the string that will be concatenated behind dst
	- dst: the string that src will be concatenated behind.
	- n: the size of total string that will be outputed. If n is 
	smaller than the length of dst, not any character of src will 
	be concatenated behind dst.
Return value: 
	The strlcat() function returns the total length 
	of the string it tried to create. That means the initial length 
	of dst plus the length of src. While this may seem somewhat confusing, 
	it was done to make truncation detection simple.
	Note, however, that if strlcat() traverses size characters without 
	finding a NUL, the length of the string is considered to be size and 
	the destination string will not be NUL-terminated (since there was 
	no space for the NULL). This keeps strlcat() from running off the 
	end of a string.
*/

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = ft_strlen(dst);
	y = ft_strlen(src) + i;
	x = 0;
	if (i >= size)
		return (size + ft_strlen(src));
	while (i < size - 1 && src[x])
	{
		dst[i] = src[x];
		i++;
		x++;
	}
	dst[i] = 0;
	return (y);
}
