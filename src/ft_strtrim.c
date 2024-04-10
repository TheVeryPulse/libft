/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:56:09 by juli              #+#    #+#             */
/*   Updated: 2024/04/10 11:30:37 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(char const *s1, char const *set);

/**
 * @brief Allocates (with malloc(3)) and returns a copy of 's1' with the 
 *        characters specified in ’set’ removed from the beginning and the end 
 *        of the string.
 * 
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	len = get_len(s1 + start, set);
	return (ft_strndup(s1 + start, len));
}

static size_t	get_len(char const *s1, char const *set)
{
	size_t	len;

	len = 0;
	while (s1[len] && !ft_strchr(set, s1[len]))
		len++;
	return (len);
}
