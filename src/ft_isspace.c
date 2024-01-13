/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <juli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:00:17 by juli              #+#    #+#             */
/*   Updated: 2023/12/13 15:11:41 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if the 'c' is a white-space character.
 * 
 * White-space characters are: ' ', '\\t', '\\n', '\\v', '\\f', and '\\r'.
 * 
 * @param c Character to check.
 * @return int 
 * Non-zero if the character is a white-space character, and zero otherwise.
 */
int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}
