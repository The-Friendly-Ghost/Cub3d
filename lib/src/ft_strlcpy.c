/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:13 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 15:12:59 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	The strlcpy() function copies strings. The strlcpy() function copies 
	up to size - 1 characters from the NUL-terminated string src to dst, 
	NUL-terminating the result.
Input: 
	- src: the string that will be copied to dst
	- dst: the string that src will be copied to.
	- n: The strlcat() function copies up to size (n) - 
	1 characters from the NUL-terminated string src to dst.
Return value: 
	The strlcpy() function returns the total length of the string it 
	tried to create. That means the length of src. While this may 
	seem somewhat confusing, it was done to make truncation detection simple.
*/

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}
