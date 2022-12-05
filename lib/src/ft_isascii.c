/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:41:13 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 12:46:30 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	Check if the input is in the Ascii table
Input: 
	- A character
Return value: 
	- 1 if the input is in the Ascii table
	- 0 if the input it not in the Ascii table
*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
