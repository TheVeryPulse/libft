/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:36:51 by juli              #+#    #+#             */
/*   Updated: 2024/01/15 00:10:07 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Parameters
	lst: The node to free.
	del: The address of the function used to delete the content.

	External functs
	free()

	Description
	Takes as a parameter a node and frees the memory of the node's content 
	using the function 'del' given as a parameter and free the node. The 
	memory of 'next' must not be freed.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}
