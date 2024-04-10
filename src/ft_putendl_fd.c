/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:26:30 by juli              #+#    #+#             */
/*   Updated: 2024/04/10 12:05:03 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Outputs the string 's' to the given file descriptor followed by a 
 *        newline
 * 
 * @param s  The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putendl_fd(char *s, int fd)
{
	char	*to_write;
	size_t	len;

	len = ft_strlen(s);
	to_write = (char *)ft_calloc(len + 1, sizeof(char));
	if (to_write)
	{
		ft_memcpy(to_write, s, len);
		to_write[len] = '\n';
		write(fd, to_write, len + 1);
		free(to_write);
	}
	else
	{
		write(fd, s, len);
		write(fd, "\n", 1);
	}
}
