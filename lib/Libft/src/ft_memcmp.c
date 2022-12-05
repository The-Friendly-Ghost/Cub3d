/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:42:28 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 14:03:26 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	The memcmp() function compares the first n bytes (each
	interpreted as unsigned char) of the memory areas s1 and s2.
Input: 
	- s1: a pointer to an array
	- s2: a pointer to an array
	- n: the amount of bytes to be compared
Return value: 
	The memcmp() function returns an integer less than, equal to, or
	greater than zero if the first n bytes of s1 is found,
	respectively, to be less than, to match, or be greater than the
	first n bytes of s2.

	For a nonzero return value, the sign is determined by the sign of
	the difference between the first pair of bytes (interpreted as
	unsigned char) that differ in s1 and s2.

	If n is zero, the return value is zero.
*/

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*x1;
	const unsigned char	*x2;

	i = 0;
	x1 = s1;
	x2 = s2;
	while (i < n)
	{
		if (x1[i] != x2[i])
			return (x1[i] - x2[i]);
		i++;
	}
	return (0);
}
