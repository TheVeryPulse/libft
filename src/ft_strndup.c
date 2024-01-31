/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:52:38 by Philip            #+#    #+#             */
/*   Updated: 2024/01/31 18:18:34 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Duplicate a string up to n characters.
 * 
 * The string is dynamically allocated and must be freed later.
 *
 * @param n   The maximum number of characters to copy.
 *
 * @return A pointer to the duplicate, or NULL if the allocation fails.
 */
char	*ft_strndup(const char *str, size_t n)
{
	char	*copy;
	size_t	len;

	len = 0;
	while (len < n && str[len])
		len++;
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, str, len);
	copy[len] = '\0';
	return (copy);
}
