/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:54:56 by Philip            #+#    #+#             */
/*   Updated: 2024/04/27 17:55:50 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_STRING_H
# define FT_FORMAT_STRING_H

# include "libft.h"
# include <stdarg.h>

extern void	add_args(t_list **strings, const char *str, va_list ap);

#endif