/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:42:57 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 14:30:24 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	The strchr() function returns a pointer to the first occurrence 
	of the character c in the string s.
Input: 
	- s: The string to examine.
	- c: the character to search for.
Return value: 
	The strchr() function returns a pointer to the 
	matched character or NULL if the character is not found.  The 
	terminating null byte is considered part of the string, so that 
	if c is specified as '\0', these functions return a pointer to 
	the terminator.
*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == 0)
	{
		while (s[i])
			i++;
		return ((char *)&s[i]);
	}
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
