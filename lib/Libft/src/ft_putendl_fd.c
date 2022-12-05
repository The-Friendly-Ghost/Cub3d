/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:42:44 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/05 09:58:37 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stddef.h>

/*
Function:
	Write an entire string, followed by a newline
Input: 
	- s: the string to be written
	- fd: the file descriptor to write to
Return value: 
	None
*/
void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
