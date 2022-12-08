/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_set.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 14:32:21 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/06 14:57:59 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_count_words(char *s, char *set)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		if (!ft_charcmp_set(s[i], set))
			wc++;
		while (!ft_charcmp_set(s[i], set) && s[i])
			i++;
		while (ft_charcmp_set(s[i], set) && s[i])
			i++;
	}
	return (wc);
}

static char	*ft_new_word(char *s, char *set)
{
	size_t	i;
	char	*str;

	i = 0;
	while (!ft_charcmp_set(s[i], set) && s[i])
		i++;
	str = malloc((i + 1) * sizeof(char));
	i = 0;
	while (!ft_charcmp_set(s[i], set) && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static void	ft_freedom(char **origin, size_t x)
{
	while (x > 0)
	{
		x--;
		free(origin[x]);
	}
	free(origin);
}

static char	**ft_add_words(char **origin, char const *s, char *set)
{
	size_t	i;
	size_t	x;

	x = 0;
	i = 0;
	while (s[i])
	{
		if (!ft_charcmp_set(s[i], set))
		{
			origin[x] = ft_new_word((char *)s + i, set);
			if (!origin[x])
			{
				ft_freedom(origin, x);
				return (0);
			}
			x++;
		}
		while (!ft_charcmp_set(s[i], set) && s[i])
			i++;
		while (ft_charcmp_set(s[i], set) && s[i])
			i++;
	}
	origin[x] = NULL;
	return (origin);
}

/**
 * @brief Allocates (with malloc(3)) and returns an array of strings
 * obtained by splitting ’s’ using the characters in the string ’set’
 * as a delimiter. The array ends with a NULL pointer.
 * @param s The string to be split.
 * @param set A string of delimiters
 * @return The array of new strings resulting from the split. 
 * NULL if the allocation fails.
 * @note
 */
char	**ft_split_set(char const *s, char *set)
{
	char	**origin;

	if (!s)
		return (0);
	origin = malloc(((ft_count_words((char *)s, set) + 1) * sizeof(char *)));
	if (!origin)
		return (0);
	origin = ft_add_words(origin, s, set);
	return (origin);
}
