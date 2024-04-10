/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:20:22 by juli              #+#    #+#             */
/*   Updated: 2024/04/08 16:29:28 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include <stdint.h>

/* Prints the address of a pointer to terminal in hexadecimal.
 * Returns the length of the printed string.
 */
int	ft_printf_p(void *p)
{
	int			i;
	uintptr_t	addr_int;
	char		s[ADDR_MAX_LEN];
	char const	*hexchars = "0123456789abcdef";

	addr_int = (uintptr_t)p;
	if (p == NULL)
		return (ft_printf_s("(nil)"));
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
	return (ft_printf_s(&s[i]));
}
