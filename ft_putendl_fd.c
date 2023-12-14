/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:26:30 by juli              #+#    #+#             */
/*   Updated: 2023/12/14 14:09:04 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Outputs the string 's' to the given file descriptor followed by a newline */
void	ft_putendl_fd(char *s, int fd)
{
	char	*to_write;
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	to_write = (char *)malloc(len + 1);
	if (!to_write)
		return ;
	i = 0;
	while (i < len)
	{
		to_write[i] = s[i];
		i++;
	}
	to_write[i++] = '\n';
	write(fd, to_write, len + 1);
	free(to_write);
}
