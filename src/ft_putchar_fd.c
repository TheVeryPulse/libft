/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <juli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:00:29 by juli              #+#    #+#             */
/*   Updated: 2023/12/13 15:36:43 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* Outputs the character 'c' to the given file descriptor. */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
