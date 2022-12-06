/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_charcmp_set.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 14:37:46 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/06 14:55:48 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief The 'character compare set' (charcmp_set), checks if a specific
 * character is part of a set. Both the character and the set are given as
 * parameters.
 * @param c The character to check
 * @param set A set (string) of characters
 * @return 1 if char 'c' is part of 'set'. 0 if this is not the case.
 * @note
 */
int	ft_charcmp_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
