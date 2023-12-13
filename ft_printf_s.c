/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <juli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:12:12 by juli              #+#    #+#             */
/*   Updated: 2023/12/13 16:06:45 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Prints a string to terminal, returns string length.
 */
int	ft_printf_s(char *s)
{
	int	len;

	if (s == NULL)
	{
		len = 6;
		write(STDOUT_FILENO, "(null)", len);
	}
	else
	{
		len = (int)ft_strlen(s);
		write(STDOUT_FILENO, s, len);
	}
	return (len);
}
