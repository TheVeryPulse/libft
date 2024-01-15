/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:09:09 by juli              #+#    #+#             */
/*   Updated: 2024/01/15 00:25:41 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Searches for a short string inside a long string up to (len) characters.

   Algorithm: brute force. */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ltl_len;

	i = 0;
	if (*little == 0)
		return ((char *)big);
	ltl_len = ft_strlen(little);
	while (big[i] && i <= len - ltl_len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && big[i + j]
			&& i + j < len)
			j++;
		if (little[j] == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
