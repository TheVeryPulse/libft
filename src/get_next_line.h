/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:54:43 by Philip            #+#    #+#             */
/*   Updated: 2024/01/08 18:09:12 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

/* Linked List

   Each node contains buffer for read() function and a pointer to
   the next node */
typedef struct s_str_list
{
	char				str[BUFFER_SIZE + 1];
	struct s_str_list	*next;
}	t_str_list;

void	_cut_line_into_buffer(char *fd_buffer, char *tmp_buffer);
void	_save_to_fd_buffer(char **fd_buffer, char *source);
void	_add_until_eol_to_list(t_str_list **head, char *buffer);
char	*_list_to_line(t_str_list *list);
int		_total_strlen_from_list(t_str_list *list);
void	_free_and_set_to_null(t_str_list **list, char **buffer);
void	_read_until_eol_or_eof_and_save_excess(int fd, char *tmp_buffer,
			t_str_list **head, char **fd_buffer);

#endif