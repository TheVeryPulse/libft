/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:54:43 by Philip            #+#    #+#             */
/*   Updated: 2024/01/08 17:56:40 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "libft.h"

int		ft_printf_all(va_list args, int str_i);
int		ft_printf_c(char c);
int		ft_printf_s(char *s);
int		ft_printf_p(void *p);
int		ft_printf_d(int n);
int		ft_printf_u(unsigned int n);
int		ft_printf_x(unsigned int n, int letter_case);

#endif