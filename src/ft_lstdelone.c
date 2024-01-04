/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <juli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:36:51 by juli              #+#    #+#             */
/*   Updated: 2023/12/13 15:32:26 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
