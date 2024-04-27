/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_add_args.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:53:59 by Philip            #+#    #+#             */
/*   Updated: 2024/04/27 17:58:25 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

extern void	add_args(t_list **strings, const char *str, va_list ap);
static void	add_literal_string(t_list **strings, const char *str, size_t start,
				size_t end);
static void	add_s(t_list **strings, va_list ap);
static void	add_d(t_list **strings, va_list ap);

extern void	add_args(t_list **strings, const char *str, va_list ap)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = 0;
	while (str[end])
	{
		if (str[end] != '%')
			end++;
		else
		{
			if (end > start)
				add_literal_string(strings, str, start, end);
			if (str[end + 1] == 's')
				add_s(strings, ap);
			else if (str[end + 1] == 'd')
				add_d(strings, ap);
			end += 2;
			start = end;
		}
	}
	if (end > start)
		add_literal_string(strings, str, start, end);
}

static void	add_literal_string(t_list **strings, const char *str, size_t start,
			size_t end)
{
	if (end > start)
	{
		ft_lstadd_back(strings,
			ft_lstnew(ft_strndup(&str[start], end - start)));
	}
}

static void	add_s(t_list **strings, va_list ap)
{
	ft_lstadd_back(strings, ft_lstnew(ft_strdup(va_arg(ap, char *))));
}

static void	add_d(t_list **strings, va_list ap)
{
	ft_lstadd_back(strings, ft_lstnew(ft_itoa(va_arg(ap, int))));
}
