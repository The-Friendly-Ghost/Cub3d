/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 12:23:20 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/11 11:48:57 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Joins return_str and total_str toghether. total_str is
 * appended to return_str
 * 
 * @param return_str 
 * @param total_str 
 * @return char* 
 */
char	*ft_strjoin_gnl(char *return_str, char *total_str)
{
	int	i;
	int	x;

	i = 0;
	while (return_str[i] != '\0')
		i++;
	x = 0;
	while (total_str[x] != '\0' && total_str[x] != '\n')
	{
		return_str[i] = total_str[x];
		i++;
		x++;
	}
	if (total_str[x] == '\n')
	{
		return_str[i] = '\n';
		i++;
	}
	return_str[i] = '\0';
	return (return_str);
}

/**
 * @brief Sets all positions in an array to zero
 * 
 * @param total 
 * @param x 
 */
void	ft_set_total_to_zero(char *total, int x)
{
	while (x <= BUFFER_SIZE)
	{
		total[x] = '\0';
		x++;
	}
	return ;
}

/**
 * @brief Don't know what this function does anymore.. It was a while ago.
 * It copies something and then sets positions to zero.
 * This whole get_next_line project could have been programmed more 
 * effeciently. But hey, at least I've learned :)
 * 
 * @param total 
 * @param i 
 * @param x 
 * @return char* 
 */
char	*ft_remove_return_from_total(char *total, int i, int x)
{
	while (total[i] != '\0' && total[i] != '\n')
		i++;
	if (total[i] == '\0')
	{
		while (x <= BUFFER_SIZE)
		{
			total[x] = '\0';
			x++;
		}
		return (total);
	}
	if (total[i] == '\n')
		i++;
	while (total[i] != '\0')
	{
		total[x] = total[i];
		x++;
		i++;
	}
	ft_set_total_to_zero(total, x);
	return (total);
}

/**
 * @brief Basically a variation of the get_next_line function. Reads 
 * BUFFER_SIZE amount of characters and adds these characters to the
 * return_str.
 * 
 * @param return_str 
 * @param total_str 
 * @param r_read 
 * @param fd 
 * @return char* 
 */
char	*fill_return(char *return_str, char *total_str, int r_read, int fd)
{
	int	size;

	r_read = read(fd, total_str, BUFFER_SIZE);
	if (r_read < 0)
	{
		free(return_str);
		return (NULL);
	}
	ft_set_total_to_zero(total_str, r_read);
	size = ft_count_str_length(total_str);
	return_str = ft_return_add_size(return_str, size);
	if (return_str == NULL)
		return (NULL);
	return_str = ft_strjoin_gnl(return_str, total_str);
	return (return_str);
}

/**
 * @brief The starting function of get_next_line. This function calls
 * all the other functions that are needed to print the next line of a file.
 * 
 * @param fd The file that has to be read.
 * @return (char*) The next line of the file
 */
char	*get_next_line(int fd)
{
	char		*return_str;
	static char	total_str[OPEN_MAX][BUFFER_SIZE + 1];
	int			size;
	int			r_read;

	if (BUFFER_SIZE <= 0 || fd > OPEN_MAX || fd < 0)
		return (NULL);
	r_read = 1;
	if (total_str[fd][0] == '\0')
		r_read = read(fd, total_str[fd], BUFFER_SIZE);
	if (r_read <= 0)
		return (NULL);
	size = ft_count_str_length(total_str[fd]);
	return_str = ft_calloc_gnl(size + 1);
	if (return_str == NULL)
		return (NULL);
	return_str = ft_memcpy_gnl(total_str[fd], return_str, size);
	while (ft_check_return(return_str, total_str[fd]) == 0)
	{
		return_str = fill_return(return_str, total_str[fd], r_read, fd);
		if (return_str == NULL)
			return (NULL);
	}
	ft_remove_return_from_total(total_str[fd], 0, 0);
	return (return_str);
}
