/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:41:46 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 13:27:23 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	Deletes and frees the given node and every 
	successor of that node, using the function ’del’ 
	and free(3). Finally, the pointer to the list 
	must be set to NULL.
Input: 
	- lst: The address of a pointer to a node.
	- del: The address of the function used to delete 
	the content of the node.
Return value: 
	none
*/

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst != NULL)
	{
		temp = *lst;
		del((*lst)->content);
		*lst = temp->next;
		free(temp);
	}
	lst = NULL;
}	
