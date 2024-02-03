/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 01:08:18 by Philip Li         #+#    #+#             */
/*   Updated: 2024/01/15 00:10:11 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees the list and every node's content.
 * 
 * The function 'del' is used to delete node content, free() is used to delete
 * node. Finally, the pointer to the list is set to NULL.
 * 
 * @param lst The address of a pointer to the list.
 * @param del The function used to delete the content of the node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current != NULL)
	{
		next = (current)->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}
