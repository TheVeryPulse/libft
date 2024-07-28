/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:43:09 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/28 17:21:36 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_atof_vars.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

/*
The string "-1.23e42" represents a floating-point number in 
scientific notation.
It means -1.23 multiplied by 10 to the power of 42.
-1.230000000000000e+42
-123000000000000000000000000000000000000000000


If you wanted to represent -1.23 times 
ten to the power of -4, it would be written as "-1.23e-4"
-1.230000000000000e-04
-0.000123
*/

static void	process_fraction_part(const char **str, t_atof_vars *vars)
{
	double	digit;

	(*str)++;
	while (ft_isdigit(**str))
	{
		digit = (**str - '0') * vars->fraction;
		if (vars->result > INFINITY - digit)
		{
			printf("Overflow: Number too large\n");
			vars->result = INFINITY;
			return ;
		}
		vars->result += digit;
		vars->fraction *= 0.1;
		(*str)++;
	}
}

static void	process_exponent_part(const char **str, t_atof_vars *vars)
{
	(*str)++;
	if (**str == '-')
	{
		vars->exponent_sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	while (ft_isdigit(**str))
	{
		if (vars->exponent > INT_MAX / 10)
		{
			printf("Overflow: Exponent too large\n");
			vars->result = INFINITY;
			return ;
		}
		vars->exponent = vars->exponent * 10 + (**str - '0');
		(*str)++;
	}
}

static void	sign_mgt(const char **str, t_atof_vars *vars)
{
	while ((**str >= '\t' && **str <= '\r') || **str == ' ')
		(*str)++;
	if (**str == '-')
	{
		vars->sign = -1.0;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
}

double	ft_atof(const char *str)
{
	t_atof_vars	vars;

	vars.result = 0.0;
	vars.exponent = 0;
	vars.sign = 1.0;
	vars.exponent_sign = 1;
	vars.fraction = 0.1;
	sign_mgt(&str, &vars);
	while (ft_isdigit(*str))
	{
		vars.result = vars.result * 10.0 + (*str - '0');
		++str;
	}
	if (*str == '.')
		process_fraction_part(&str, &vars);
	if (*str == 'e' || *str == 'E')
		process_exponent_part(&str, &vars);
	vars.result *= pow(10.0, vars.exponent_sign * vars.exponent);
	return (vars.sign * vars.result);
}
