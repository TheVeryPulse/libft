/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:27:11 by juli              #+#    #+#             */
/*   Updated: 2024/04/10 11:31:11 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the 
 *        string 's'. The substring begins at index 'start'’' and is of  maximum
 *        size 'len'.
 * 
 * @param s  The string from which to create the substring.
 * @param start The start index of the substring in the string 's'.
 * @param len The maximum length of the substring.
 * 
 * @return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (start >= ft_strlen(s) || len == 0)
		return ((char *)ft_calloc(1, 1));
	return (ft_strndup(s + start, len));
}
