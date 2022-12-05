/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:16 by cpost         #+#    #+#                 */
/*   Updated: 2022/10/06 15:23:07 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	The strlen() function calculates the length of the string pointed 
	to by s, excluding the terminating null byte ('\0').
Input: 
	- s: the string to be counted
Return value: 
	The strlen() function returns the number of bytes in the string 
	pointed to by s.
*/

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}
