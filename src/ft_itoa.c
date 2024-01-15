/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:40:23 by juli              #+#    #+#             */
/*   Updated: 2024/01/15 00:07:46 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define INT_MAX_LEN (40)
#define DEC_BASE (10)

char	*ft_itoa(int n)
{
	int			i;
	bool		is_negative;
	char		s[INT_MAX_LEN];
	char const	*dec_chars = "0123456789";

	i = INT_MAX_LEN - 1;
	s[i--] = '\0';
	is_negative = n < 0;
	while (n >= DEC_BASE || n <= -(DEC_BASE))
	{
		s[i] = dec_chars[ft_abs(n % DEC_BASE)];
		n /= DEC_BASE;
		i--;
	}
	s[i] = dec_chars[ft_abs(n)];
	if (is_negative)
		s[--i] = '-';
	return (ft_strdup(&s[i]));
}
