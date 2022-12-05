/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:40:05 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 12:38:03 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	Convert a string to an integer
Input: 
	- a string (const char *nptr)
Return value: 
	the first integer found in the string. If no integer is found
	inside the string, a 0 is returned.
Examples:
	- "  51624 61" would return "51624"
	- " -253 a 25" would return -253
*/

static int	ft_getnumber(const char *ptr, int c)
{
	int	num;

	num = 0;
	while (*ptr >= '0' && *ptr <= '9')
	{
		num = (*ptr - 48) + (num * 10);
		ptr++;
	}
	return (num * c);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	c;

	i = 0;
	c = 1;
	while (nptr[i] == '\n' || nptr[i] == '\t' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			c = -c;
		i++;
	}
	if (nptr[i] >= '0' && nptr[i] <= '9')
		return (ft_getnumber(nptr + i, c));
	return (0);
}
