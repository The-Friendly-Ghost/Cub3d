/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:28 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 15:29:22 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	The strrchr() function returns a pointer to the last occurrence of 
	the character c in the string s.
Input: 
	- s: string to search
	- c: character to find
Return value: 
	The strrchr() function returns a pointer to the 
	matched character or NULL if the character is not found. The 
	terminating null byte is considered part of the string, so 
	that if c is specified as '\0', these functions return a 
	pointer to the terminator.
*/

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i != 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}
