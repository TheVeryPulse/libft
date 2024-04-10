/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_part1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 19:16:02 by Philip            #+#    #+#             */
/*   Updated: 2024/04/08 16:25:49 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftprintf.h"
#include <stdbool.h>

static bool	is_specifier(char c);
static void	str_upper(char *s);
static int	ft_dprintf_all(int fd, va_list args, int str_i);
static int	ft_dprintf_x(int fd, unsigned int n, int letter_case);

int	ft_dprintf(int fd, const char *str, ...)
{
	int		i;
	int		sum;
	va_list	args;

	va_start(args, str);
	sum = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			sum += ft_dprintf_c(fd, str[i]);
		else if (is_specifier(str[i + 1]))
			sum += ft_dprintf_all(fd, args, str[++i]);
		else
			return (-1);
		i++;
	}
	va_end(args);
	return (sum);
}

static int	ft_dprintf_all(int fd, va_list args, int str_i)
{
	int	sum;

	sum = 0;
	if (str_i == 'c')
		sum += ft_dprintf_c(fd, va_arg(args, int));
	else if (str_i == 's')
		sum += ft_dprintf_s(fd, va_arg(args, char *));
	else if (str_i == 'p')
		sum += ft_dprintf_p(fd, va_arg(args, void *));
	else if (str_i == 'd' || str_i == 'i')
		sum += ft_dprintf_d(fd, va_arg(args, int));
	else if (str_i == 'u')
		sum += ft_dprintf_u(fd, va_arg(args, unsigned int));
	else if (str_i == 'x' || str_i == 'X')
		sum += ft_dprintf_x(fd, va_arg(args, int), str_i);
	else if (str_i == '%')
		sum += ft_dprintf_c(fd, '%');
	else
		return (-1);
	return (sum);
}

static bool	is_specifier(char c)
{
	return (ft_strchr("cspdiuxX%%", c) != NULL);
}

/* Converts all lower case letters to upper case in a string */
static void	str_upper(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
}

static int	ft_dprintf_x(int fd, unsigned int n, int letter_case)
{
	int			i;
	char		s[HEXA_MAX_LEN];
	char const	*hexchars = "0123456789abcdef";

	i = HEXA_MAX_LEN - 1;
	s[i--] = '\0';
	while (n >= HEXA_BASE)
	{
		s[i] = hexchars[ft_abs(n % HEXA_BASE)];
		n = ft_abs(n / HEXA_BASE);
		i--;
	}
	s[i] = hexchars[ft_abs(n)];
	if (letter_case == 'X')
		str_upper(&s[i]);
	return (ft_dprintf_s(fd, &s[i]));
}
