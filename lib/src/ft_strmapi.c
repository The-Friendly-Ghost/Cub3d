/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:19 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 15:15:36 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	Applies the function ’f’ to each character of the 
	string ’s’, and passing its index as first argument 
	to create a new string (with malloc(3)) resulting 
	from successive applications of ’f’.
Input: 
	- s: The string on which to iterate.
	- f: The function to apply to each character.
Return value: 
	The string created from the successive applications 
	of ’f’. Returns NULL if the allocation fails.
*/

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (0);
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
