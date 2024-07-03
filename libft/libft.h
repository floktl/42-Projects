/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:57:56 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 19:52:04 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}			t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
int		ft_lstsize(t_list *lst);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_itoa(int n);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstclear(t_list **lst, void (*del)(int));
void	ft_lstiter(t_list *lst, void (*f)(int));
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(int), void (*del)(int));

//	Personal added functions

void	free_two_dimensional_array(char **param);
void	*ft_realloc(void *ptr, size_t size);
int		append_int(int a, int b);
char	bits_to_char(const int bits[8]);
int		is_substr_first_word(const char *str, const char *sub_str, int st);
void	remove_char(char *str, char char_to_remove, int old_len, int *end);
int		replace_substr(char **s, char **sub_str, char *new_str, int position);
int		alloc_string(char **s, int result_len);
char	*insert_char_at_position(char *s, char c, size_t len, size_t pos);
int		null_term_string(char **command_str);
char	*strjoin_free(char *s1, char *s2, int num);
void	rem_char(char *str, int pos);

// printf_functions:

//main function for printing
int		ft_printf(const char *format, ...);
//checking which datatypes are given
int		ft_checkcases(const char format, va_list argument);
//functions for handling special data formats
int		put_u(unsigned int n);
int		put_hex(unsigned long *hexadecimal, int upper_lower, int counter);
int		put_i(int n, int counter);
int		put_p(va_list argument);
//functions for the actual printing
int		ft_printstr(char *str, int counter);
int		ft_putchar(int c, int counter);

//get_next_line functions:
char	*get_next_line(int fd);

#endif
