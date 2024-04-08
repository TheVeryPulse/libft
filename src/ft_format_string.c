/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:51:05 by Philip            #+#    #+#             */
/*   Updated: 2024/04/08 16:26:20 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static size_t	format_strlen(const char *s, va_list ap_copy);
static void		build_format_string(char *f_str, const char *str, size_t len,
					va_list ap);

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
char	*ft_format_string(const char *str, ...)
{
	size_t	len;
	va_list	ap;
	char	*f_str;

	len = 0;
	va_start(ap, str);
	len = format_strlen(str, ap);
	va_end(ap);
	f_str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!f_str)
		return (NULL);
	va_start(ap, str);
	build_format_string(f_str, str, len, ap);
	va_end(ap);
	return (f_str);
}

static size_t	format_strlen(const char *s, va_list ap_copy)
{
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (ft_strncmp(&s[i], "%s", 2) == 0)
		{
			len += ft_strlen(va_arg(ap_copy, char *));
			i += 2;
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

static void	build_format_string(char *f_str, const char *str, size_t len,
			va_list ap)
{
	size_t	i;
	size_t	j;

	if (!f_str)
		return ;
	i = 0;
	j = 0;
	while (j < len)
	{
		if (ft_strncmp(&str[i], "%s", 2) == 0)
		{
			i += 2;
			ft_strlcpy(&f_str[j], va_arg(ap, char *), len);
		}
		else
			f_str[j++] = str[i++];
		while (f_str[j])
			j++;
	}
	f_str[j] = '\0';
}

/* int	main(int argc, char **argv)
{
	char	*f_str;

	f_str = ft_format_string("%s\n", argv[2]);
	ft_printf("%s", f_str);
	free(f_str);
} */
