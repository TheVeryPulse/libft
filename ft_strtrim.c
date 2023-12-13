/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <juli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:56:09 by juli              #+#    #+#             */
/*   Updated: 2023/12/13 15:57:58 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool		char_in_str(char c, const char *str);

static size_t	get_new_len(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	new_len;
	char	*new;

	i = 0;
	while (s1[i] && char_in_str(s1[i], set))
		i++;
	start = i;
	new_len = get_new_len(s1, set);
	new = (char *)malloc((new_len + 1) * sizeof(char));
	i = 0;
	while (i < new_len)
	{
		new[i] = s1[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static bool	char_in_str(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (true);
		i++;
	}
	return (false);
}

static size_t	get_new_len(char const *s1, char const *set)
{
	size_t	start_i;
	size_t	end_i;
	size_t	new_len;

	start_i = 0;
	while (s1[start_i] && char_in_str(s1[start_i], set))
		start_i++;
	end_i = ft_strlen(s1) - 1;
	while (char_in_str(s1[end_i], set) && end_i >= start_i)
		end_i--;
	new_len = end_i - start_i + 1;
	return (new_len);
}
