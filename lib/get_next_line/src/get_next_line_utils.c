/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 12:23:24 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/11 11:36:42 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Allocates memory and fills the spots with null characters.
 * 
 * @param size the size the array has to be
 * @return (char*) an array of length 'size' filled with null characters
 */
char	*ft_calloc_gnl(int size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(size * sizeof(char) + 1);
	if (ptr)
	{
		while (size > 0)
		{
			ptr[i] = '\0';
			i++;
			size--;
		}
	}
	return (ptr);
}

/**
 * @brief Counts and returns the amount of characters in the total_str until a
 *  newline or null character is reached.
 * 
 * @param total_str 
 * @return int
 */
int	ft_count_str_length(char *total_str)
{
	int	i;

	i = 0;
	while (total_str[i] != '\0')
	{
		if (total_str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i + 1);
}

/**
 * @brief copies the content of the src ('total_str') string to 
 * the destination string (return_str).
 * 
 * @param src Source string (total_str)
 * @param dest Destination string (return_str)
 * @param n amount of characters to be copied
 * @return char* 
 */
char	*ft_memcpy_gnl(char *src, char *dest, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (0);
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/**
 * @brief Checks the current return string to see if the end of the
 * line is reached (newline character). If so, return 1. Also checks
 * if the EOF is reached (by checkig if total_str == '\0').
 * 
 * @param return_str 
 * @param total_str 
 * @return 1 if end of line is reached. 0 if end of line is not yet reached
 */
int	ft_check_return(char *return_str, char *total_str)
{
	int	i;

	i = 0;
	if (total_str[0] == '\0')
		return (1);
	while (return_str[i] != '\0' )
	{
		if (return_str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_return_add_size(char *return_str, int size)
{
	char	*new_return;
	int		i;

	i = 0;
	while (return_str[i] != '\0')
		i++;
	new_return = ft_calloc_gnl((i + size) * sizeof(char));
	if (new_return == NULL)
	{
		free(return_str);
		return (NULL);
	}
	i = 0;
	while (return_str[i] != '\0')
	{
		new_return[i] = return_str[i];
		i++;
	}
	free(return_str);
	return (new_return);
}
