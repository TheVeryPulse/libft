/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:56:09 by juli              #+#    #+#             */
/*   Updated: 2024/01/15 00:26:18 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(char const *s1, char const *set);

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
