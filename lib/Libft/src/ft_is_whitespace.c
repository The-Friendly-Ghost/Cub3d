/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_is_whitespace.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 10:40:24 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/08 10:42:54 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is a whitespace
 * @param c The character to check
 * @return 1 if c is whitespace. 0 if c is not whitespace.
 * @note
 */
int	ft_is_whitespace(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	return (0);
}
