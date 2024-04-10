/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:54:43 by Philip            #+#    #+#             */
/*   Updated: 2024/04/10 11:32:52 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H
# include "libft.h"
# include <stdarg.h>

# define HEXA_BASE 16
# define HEXA_MAX_LEN 9
# define ADDR_MAX_LEN 20

# define DEC_BASE 10
# define DEC_MAX_LEN 16

/* ft_printf */

int		ft_printf_all(va_list args, int str_i);
int		ft_printf_c(char c);
int		ft_printf_s(char *s);
int		ft_printf_p(void *p);
int		ft_printf_d(int n);
int		ft_printf_u(unsigned int n);
int		ft_printf_x(unsigned int n, int letter_case);

/* ft_dprintf */

int		ft_dprintf_c(int fd, const char c);
int		ft_dprintf_s(int fd, const char *s);
int		ft_dprintf_p(int fd, const void *p);
int		ft_dprintf_d(int fd, int n);
int		ft_dprintf_u(int fd, unsigned int n);

#endif