/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:44:18 by juli              #+#    #+#             */
/*   Updated: 2024/04/08 16:37:20 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a new node.
 * 
 * The node content is initialized with the value of the parameter'content'. The
 * next node is initialized to NULL.
 * 
 * @param content The content to be placed in the new node.
 * 
 * @return (t_list*) Returns a pointer to the new node, or NULL if the allocation
 * fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	return (node);
}
