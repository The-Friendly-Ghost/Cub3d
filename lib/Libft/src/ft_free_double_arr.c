/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_double_arr.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 11:41:15 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/08 12:49:47 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Free all pointers in a double array, and lastly free the double array
 * pointer itself.
 * @param arr Pointer to double array
 * @return Nothing
 * @note
 */
void	ft_free_double_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i])
		free(arr[i++]);
	free (arr);
}
