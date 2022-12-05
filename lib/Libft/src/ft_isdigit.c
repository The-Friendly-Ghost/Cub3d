/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:41:16 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 12:47:37 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	Check if the input is a single digit (from 0 to 9).
Input: 
	- An integer
Return value: 
	- 1 if the input is a digit
	- 0 if the input it not a digit
*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
