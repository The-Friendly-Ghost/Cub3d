/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:41:51 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 13:27:08 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	Iterates the list ’lst’ and applies the function 
	’f’ on the content of each node.
Input: 
	- lst: The address of a pointer to a node.
	- f: The address of the function used to iterate on 
	the list.
Return value: 
	none
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f((lst)->content);
		lst = lst->next;
	}
}
