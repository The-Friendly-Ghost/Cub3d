/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:41:44 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 13:22:59 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	Adds the node ’new’ at the beginning of the list.
Input: 
	- lst: The address of a pointer to the first link of
	a list.
	- new: The address of a pointer to the node to be
	added to the list.
Return value: 
	none
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
