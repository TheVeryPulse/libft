/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:27:11 by juli              #+#    #+#             */
/*   Updated: 2024/01/15 00:26:26 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Allocates (with malloc(3)) and returns a substring from the string 's'.
	The substring begins at index 'start' and is of maximum size 'len'.*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;
	size_t	newlen;

	if (start >= ft_strlen(s) || len == 0)
		return ((char *)ft_calloc(1, 1));
	newlen = ft_strlen(&s[start]);
	if (newlen > len)
		newlen = len;
	newstr = (char *)malloc((newlen + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (i < newlen)
	{
		newstr[i] = s[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
