/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:51:05 by Philip            #+#    #+#             */
/*   Updated: 2024/01/11 20:13:00 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
char	*format_string(const char *str, ...)
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

	if (!f_str)
		return ;
	i = 0;
	while (i < len)
	{
		if (ft_strncmp(&str[i], "%s", 2) == 0)
			ft_strlcpy(&f_str[i], va_arg(ap, char *), len);
		else
			f_str[i] = str[i];
		while (f_str[i])
			i++;
	}
	f_str[i] = '\0';
}

// int	main(void)
// {
// 	char	*f_str;

// 	f_str = format_string("Test: %s", "0123456789");
// 	ft_printf("%s\n", f_str);
// 	free(f_str);
// }
