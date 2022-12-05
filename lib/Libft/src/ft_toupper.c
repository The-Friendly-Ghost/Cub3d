/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:50 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 15:35:00 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	Converts a lowercase letter to uppercase. If another character is passed 
	as a parameter, this parameter will be returned.
Input: 
	- c: character to convert
Return value: 
	Uppercase letter or 'c' if the character is not alphabetic
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= ('a' - 'A');
	return (c);
}
