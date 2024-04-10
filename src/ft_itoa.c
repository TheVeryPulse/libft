/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:40:23 by juli              #+#    #+#             */
/*   Updated: 2024/04/10 11:34:55 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

#define INT_MAX_LEN 40
#define DEC_BASE 10

/**
 * @brief Allocates (with malloc(3)) and returns a string representing the 
 *        integer received as an argument.
 * 
 * @param n the integer to convert.
 * @return The string representing the integer. NULL if the allocation fails.
 */
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
