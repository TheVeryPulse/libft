/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:39:36 by juli              #+#    #+#             */
/*   Updated: 2024/01/11 14:49:08 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_str_count(char const *s, char d);

static char		*extract_str(char const *s, char c);

/**
 * @brief Splits a string into an array of strings (words) using a specified
 * delimiter character.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return 
 * A dynamically allocated array of strings. Each string is a word from the
 * original string 's'. The array is terminated by a NULL pointer. If the
 * allocation fails, the function returns NULL.
 * 
 * The memory for the array and for each word is dynamically allocated and must
 * be freed by the caller.*/
char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	total;
	char	**strs;

	total = get_str_count(s, c);
	strs = (char **)malloc((total + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			strs[j] = extract_str(&s[i], c);
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	strs[j] = NULL;
	return (strs);
}

static size_t	get_str_count(char const *s, char d)
{
	size_t	i;
	size_t	sum;

	i = 0;
	sum = 0;
	while (s[i])
	{
		while (s[i] == d)
			i++;
		if (s[i] != d && s[i])
			sum++;
		while (s[i] != d && s[i])
			i++;
	}
	return (sum);
}

static char	*extract_str(char const *s, char c)
{
	char	*out_str;
	size_t	i;
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	out_str = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	while (s[i] != c && i < len)
	{
		out_str[i] = s[i];
		i++;
	}
	out_str[i] = '\0';
	return (out_str);
}
