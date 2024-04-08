/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_part2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 19:37:00 by Philip            #+#    #+#             */
/*   Updated: 2024/04/08 16:43:54 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

int	ft_dprintf_c(int fd, const char c)
{
	return (write(fd, &c, 1));
}

int	ft_dprintf_s(int fd, const char *s)
{
	int	len;

	if (s == NULL)
	{
		len = 6;
		write(fd, "(null)", len);
	}
	else
	{
		len = (int)ft_strlen(s);
		write(fd, s, len);
	}
	return (len);
}

int	ft_dprintf_p(int fd, const void *p)
{
	int			i;
	uintptr_t	addr_int;
	char		s[ADDR_MAX_LEN];
	char const	*hexchars = "0123456789abcdef";

	addr_int = (uintptr_t)p;
	if (p == NULL)
		return (ft_dprintf_s(fd, "(nil)"));
	i = ADDR_MAX_LEN - 1;
	s[i--] = '\0';
	while (addr_int >= HEXA_BASE)
	{
		s[i] = hexchars[addr_int % HEXA_BASE];
		addr_int /= HEXA_BASE;
		i--;
	}
	s[i--] = hexchars[addr_int];
	s[i--] = 'x';
	s[i] = '0';
	return (ft_dprintf_s(fd, &s[i]));
}

int	ft_dprintf_d(int fd, int n)
{
	int			i;
	bool		is_negative;
	char		s[DEC_MAX_LEN];
	char const	*dec_chars = "0123456789";

	is_negative = (n < 0);
	i = DEC_MAX_LEN - 1;
	s[i--] = '\0';
	while (n >= DEC_BASE || n <= -(DEC_BASE))
	{
		s[i] = dec_chars[ft_abs(n % DEC_BASE)];
		n = ft_abs(n / DEC_BASE);
		i--;
	}
	s[i] = dec_chars[ft_abs(n)];
	if (is_negative)
		s[--i] = '-';
	return (ft_dprintf_s(fd, &s[i]));
}

int	ft_dprintf_u(int fd, unsigned int n)
{
	int			i;
	char		s[DEC_MAX_LEN];
	char const	*dec_chars = "0123456789";

	i = DEC_MAX_LEN - 1;
	s[i--] = '\0';
	while (n >= DEC_BASE)
	{
		s[i] = dec_chars[n % DEC_BASE];
		n /= DEC_BASE;
		i--;
	}
	s[i] = dec_chars[n];
	return (ft_dprintf_s(fd, &s[i]));
}
