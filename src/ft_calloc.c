/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/01/15 00:37:49 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

/**
 * @brief
 * Allocates memory for an array of 'nmemb' elements of 'size' bytes each and
 * returns a pointer to the allocated memory. The memory is set to zero.
 *
 * Checks for overflow when calculating the total size of memory to allocate.
 *
 * @param nmemb Number of elements to be allocated.
 * @param size Size of each element.
 * @return void*
 * A pointer to the allocated memory initialized to zero. 
 * If allocation fails, or if overflow occurs when calculating the total size,
 * the function returns NULL.
 * If 'nmemb' or 'size' is 0, the function returns a unique pointer that can be
 * successfully passed to free(). */
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ary;
	size_t	bsize;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	bsize = nmemb * size;
	if (bsize < nmemb || bsize < size)
		return (NULL);
	ary = (void *)malloc(bsize);
	if (ary == NULL)
		return (NULL);
	ft_bzero(ary, bsize);
	return (ary);
}
