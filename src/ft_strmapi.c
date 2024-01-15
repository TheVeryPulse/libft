/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:54:22 by juli              #+#    #+#             */
/*   Updated: 2024/01/15 00:25:00 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Applies a given function 'f' to each character of the input 
 * string 's'.
 * Each character is passed by its index as the first argument to 'f'.
 * A new string is created, where each character is the result of the function 
 * 'f'.
 * 
 * If the input string 's' is NULL, the function returns NULL.
 * If memory allocation for the new string fails, the function also returns NULL.
 * The new string is null-terminated and returned by the function.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*newstr;

	if (!s)
		return (NULL);
	newstr = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
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
