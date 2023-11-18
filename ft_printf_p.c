/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip Li <LJHR.UK@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:20:22 by juli              #+#    #+#             */
/*   Updated: 2023/11/18 00:32:49 by Philip Li        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Prints the address of a pointer to terminal in hexadecimal.
 * Returns the length of the printed string.
 */

#include <unistd.h>
#include <stdint.h>
#include "libft.h"

#define HEXA_BASE (16)
#define ADDR_MAX_LEN (20)

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
