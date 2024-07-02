/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstr_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:26:32 by Philip            #+#    #+#             */
/*   Updated: 2024/07/02 22:26:32 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	main(void)
{
	char	*f_str;

	f_str = ft_format_string(" %d %s\n", 100, " >>>string test<<< ");
	ft_printf("%s", f_str);
	free(f_str);
}
