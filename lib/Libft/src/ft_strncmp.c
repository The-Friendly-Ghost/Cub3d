/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:22 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 15:22:56 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	The strncmp() function compares the first (at most) n bytes 
	of s1 and s2 two strings s1 and s2. 
Input: 
	- s1: string 1
	- s2: string 2
	- n: amount of bytes to compare
Return value: 
	Returns an integer less than, equal to, or greater than zero 
	if s1 is found, respectively, to be less than, to match, or 
	be greater than s2. 
*/

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (!(s1[i]) || !(s2[i]))
			return (0);
		i++;
	}
	return (0);
}
