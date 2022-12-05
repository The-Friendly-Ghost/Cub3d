/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:39 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 15:35:21 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	Converts a uppercase letter to lowercase. If another character is passed 
	as a parameter, this parameter will be returned.
Input: 
	- c: character to convert
Return value: 
	Lowercase letter or 'c' if the character is not alphabetic
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += ('a' - 'A');
	return (c);
}
