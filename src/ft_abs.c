/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:32:59 by juli              #+#    #+#             */
/*   Updated: 2024/01/15 00:06:53 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns the absolute value of an interger
 * Does not handle int overflow
 */
int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}
