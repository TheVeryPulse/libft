/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:06:56 by juli              #+#    #+#             */
/*   Updated: 2024/04/08 16:29:58 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include <stdbool.h>

static bool	is_specifier(char c);

/**
 * After %:
 * • c : single character.
 * • s : string.
 * • p : The void * pointer in hexadecimal format.
 * • d : decimal (base 10) number.
 * • i : integer in base 10.
 * • u : unsigned decimal (base 10) number.
 * • x : number in hexadecimal (base 16) lowercase format.
 * • X : a number in hexadecimal (base 16) uppercase format.
 * • % : a percent sign. */
int	ft_printf(const char *str, ...)
{
	int		i;
	int		sum;
	va_list	args;

	va_start(args, str);
	i = 0;
	sum = 0;
	while (str[i])
	{
		if (str[i] != '%')
			sum += ft_printf_c(str[i]);
		else if (is_specifier(str[i + 1]))
			sum += ft_printf_all(args, str[++i]);
		else
			return (-1);
		i++;
	}
	va_end(args);
	return (sum);
}

/* Check if input character is a valid specifier (cspiduxX%) */
static bool	is_specifier(char c)
{
	return (ft_strchr("cspdiuxX%%", c) != NULL);
}
