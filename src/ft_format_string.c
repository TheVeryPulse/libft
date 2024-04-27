/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:51:05 by Philip            #+#    #+#             */
/*   Updated: 2024/04/27 17:57:29 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_format_string.h"
#include "libft.h"
#include <stdarg.h>

extern char	*ft_format_string(const char *str, ...);
static char	*build_format_string(t_list *strings);

/**
 * @brief Formats a string by replacing '%s' with additional string arguments.
 *
 * @param str The string to be formatted. It should contain '%s' to be replaced
 * by additional arguments.
 * @param ... Variable number of additional arguments.
 * 
 * @return char*
 * A pointer to the formatted string. It is dynamically allocated and should be
 * freed by the caller.
 *
 * If memory allocation fails, the function returns NULL. 
 */
extern char	*ft_format_string(const char *str, ...)
{
	va_list	ap;
	t_list	*strings;

	strings = NULL;
	va_start(ap, str);
	add_args(&strings, str, ap);
	va_end(ap);
	return (build_format_string(strings));
}

static char	*build_format_string(t_list *strings)
{
	char	*f_str;
	t_list	*node;
	size_t	len;

	len = 0;
	node = strings;
	while (node)
	{
		len += ft_strlen((char *)node->content);
		node = node->next;
	}
	f_str = ft_calloc(len + 1, sizeof(char));
	node = strings;
	while (node)
	{
		ft_strlcat(f_str, (char *)node->content, len + 1);
		node = node->next;
	}
	return (f_str);
}
