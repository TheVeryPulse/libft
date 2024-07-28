/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:21:39 by Philip            #+#    #+#             */
/*   Updated: 2024/07/28 17:29:22 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

// gcc test/atof_test.c -Iinc -Llib -lft -lm

void	test_atof(const char *str)
{
	printf("ft_atof:: Result: %f\n", ft_atof(str));
	printf("atof:: Result   : %f\n", atof(str));
}

int main(void)
{
	double	atof_res;
	double	ft_atof_res;
	
	test_atof("-1.23e42");
	test_atof("0.0");
	test_atof("00.0");
	test_atof("1.01");
	test_atof("-1.9");
	test_atof("+0.003");
	test_atof("+0300.00300");
	test_atof("0.100");
	// test_atof();
	// test_atof();


	return (0);
}
