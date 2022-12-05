/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nulloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 11:10:08 by cpost         #+#    #+#                 */
/*   Updated: 2022/10/25 11:22:33 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

/**
 * @brief Creates a new array filled with NULL pointers.
 * @param n_point The amount of NULL pointers to create.
 * @return Pointer to the newly created array
 * @note
 */
char	**ft_nulloc(int n_point)
{
	char	**ptr;
	int		i;

	ptr = malloc(n_point * sizeof(char *));
	if (ptr)
	{
		i = 0;
		while (i < n_point)
			ptr[i++] = NULL;
	}
	return (ptr);
}
