/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:54:22 by juli              #+#    #+#             */
/*   Updated: 2024/04/10 11:37:30 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Applies the function `f` to each character of the string `s`, passing
 *        its index as the first argument and the character itself as the 
 *        second. A new string is created (using malloc(3)) to collect the
 *        results from the successive applications of f.
 * 
 * @param s The string on which to iterate.
 * @param f The function to apply to each character
 * @return  The string created from the successive applications of `f`.
            Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*newstr;

	if (!s)
		return (NULL);
	newstr = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
