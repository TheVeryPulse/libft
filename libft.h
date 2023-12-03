/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip Li <LJHR.UK@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:03:04 by juli              #+#    #+#             */
/*   Updated: 2023/12/03 16:43:58 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/* basic functions */

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

size_t	ft_strlen(const char *s);

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *s, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

int		ft_toupper(int c);

int		ft_tolower(int c);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

char	*ft_strnstr(const char *big, const char *little, size_t len);

int		ft_atoi(const char *nptr);

void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_strdup(const char *s);

/* additional functions */

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s1, char const *set);

char	**ft_split(char const *s, char c);

char	*ft_itoa(int n);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

/* Linked List */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ft_printf */

int		ft_printf(const char *str, ...);

int		ft_printf_all(va_list args, int str_i);

int		ft_printf_c(char c);

int		ft_printf_s(char *s);

int		ft_printf_p(void *p);

int		ft_printf_d(int n);

int		ft_printf_u(unsigned int n);

int		ft_printf_x(unsigned int n, int letter_case);

int		ft_abs(int n);

/* get_next_line */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (16)
# endif
# ifndef FD_MAX
#  define FD_MAX (4096)
# endif

/* Linked List

   Each node contains buffer for read() function and a pointer to
   the next node */
typedef struct s_str_list
{
	char				str[BUFFER_SIZE + 1];
	struct s_str_list	*next;
}	t_str_list;

char	*get_next_line(int fd);

void	_cut_line_into_buffer(char *fd_buffer, char *tmp_buffer);

void	_save_to_fd_buffer(char **fd_buffer, char *source);

void	_add_until_eol_to_list(t_str_list **head, char *buffer);

char	*_list_to_line(t_str_list *list);

int		_total_strlen_from_list(t_str_list *list);

void	_free_and_set_to_null(t_str_list **list, char **buffer);

void	_read_until_eol_or_eof_and_save_excess(int fd, char *tmp_buffer,
			t_str_list **head, char **fd_buffer);

#endif
