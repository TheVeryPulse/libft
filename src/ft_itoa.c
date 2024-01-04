/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <juli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:40:23 by juli              #+#    #+#             */
/*   Updated: 2023/12/13 15:31:26 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>

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
