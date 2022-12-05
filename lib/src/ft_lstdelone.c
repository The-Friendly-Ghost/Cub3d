/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:41:49 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 13:27:39 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	Takes as a parameter a node and frees the memory of 
	the node’s content using the function ’del’ given 
	as a parameter and free the node. The memory of 
	’next’ must not be freed.
Input: 
	- lst: The node to free.
	- del: The address of the function used to delete 
	the content.
Return value: 
	none
*/

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}
