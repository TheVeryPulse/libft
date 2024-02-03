/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:40:17 by juli              #+#    #+#             */
/*   Updated: 2024/02/03 18:44:22 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

#define DEC_BASE (10)
#define DEC_MAX_LEN (12)

/* Prints an unsigned integer to terminal, return string length.
 */
int	ft_printf_u(unsigned int n)
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
	return (ft_printf_s(&s[i]));
}
