/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:33:34 by juli              #+#    #+#             */
/*   Updated: 2023/12/03 16:37:51 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns a pointer to the first occurence of character (c) in the string (s).

   Return NULL if character (c) is not found */
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
#include <string.h>

int	main(void)
{
	char str[] = "tripouille";
	char c = 't' + 256;
	printf("ft: (%c) in (%s): (%s) at (%p)\n",
		c, str, ft_strchr(str, 't' + 256), ft_strchr(str, 't' + 256));
	printf("c:  (%c) in (%s): (%s) at (%p)\n",
		c, str, strchr(str, 't' + 256), strchr(str, 't' + 256));
}
*/
