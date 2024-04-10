/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:37:41 by juli              #+#    #+#             */
/*   Updated: 2024/01/15 00:24:13 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	total_len;

	i = 0;
	while (dst[i] && i < size)
		i++;
	dst_len = ft_strlen(dst);
	if (dst_len != i)
		dst_len = size;
	total_len = dst_len + ft_strlen((char *)src);
	if (size == 0)
		return (total_len);
	i = 0;
	j = 0;
	while (i < size - 1 && dst[i])
		i++;
	while (i < size - 1 && src[j])
		dst[i++] = src[j++];
	if (i >= dst_len)
		dst[i] = '\0';
	return (total_len);
}
