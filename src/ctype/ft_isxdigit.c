/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 02:59:29 by Philip            #+#    #+#             */
/*   Updated: 2024/04/10 11:33:33 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** @brief checks for hexadecimal digits, that is, one of
           0 1 2 3 4 5 6 7 8 9 a b c d e f A B C D E F. 
*/
int	ft_isxdigit(int c)
{
	return (ft_isdigit(c)
		|| (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'));
}
