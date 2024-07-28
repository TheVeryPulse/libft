/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_atof_vars.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:18:58 by Philip            #+#    #+#             */
/*   Updated: 2024/07/28 17:19:31 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ATOF_VARS_H
# define T_ATOF_VARS_H

typedef struct s_atof_vars
{
	double	result; // 0.0
	int		exponent; // 0
	double	sign; // 1.0
	int		exponent_sign; // 1
	double	fraction; // 0.1
}	t_atof_vars;

#endif /* T_ATOF_VARS_H */
