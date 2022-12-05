/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:40:52 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 12:41:41 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	Fill an array with zero's for n positions
Input: 
	- An array (void *s)
	- The amount of positions in the array that have to be filled with 0
Return value: 
	An array filled with 0's for N positions
*/

#include <stddef.h>

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*x;

	x = s;
	while (n > 0)
	{
		*x = 0;
		x++;
		n--;
	}
	return (s);
}
