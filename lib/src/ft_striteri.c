/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:05 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 14:33:23 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	Applies the function ’f’ on each character of 
	the string passed as argument, passing its index 
	as first argument. Each character is passed by 
	address to ’f’ to be modified if necessary.
Input: 
	- s:  The string on which to iterate.
	- f: The function to apply to each character.
Return value: 
	None
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
