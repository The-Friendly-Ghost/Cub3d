/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:41:10 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 12:45:50 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	Check if the input is a letter from the (Latin) alphabet
Input: 
	- A character
Return value: 
	- 1 if the input is a letter from the (Latin) alphabet
	- 0 if the input it not a letter from the (Latin) alphabet
*/

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
