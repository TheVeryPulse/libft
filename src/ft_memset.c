/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:00:21 by juli              #+#    #+#             */
/*   Updated: 2024/01/15 00:10:24 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Fills the first 'n' bytes of the memory area pointed to by 's' with 
 * byte 'c'.
 * 
 * @param s Memory area to be filled.
 * @param c Constant byte to fill the memory area with.
 * @param n Number of bytes to be filled.
 * 
 * @return (void*) Returns a pointer to the memory area 's'.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = c;
	return (s);
}
