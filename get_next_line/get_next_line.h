/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:30:42 by fkeitel           #+#    #+#             */
/*   Updated: 2023/11/18 19:50:40 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
void	*ft_memmove(void *dst, const void *src, int len);
char	*double_bufsize_fill_with_null(char const *s1);
void	*extract_line(char **line, char **buf, int *end);
size_t	ft_strlen(const char *c);
int		read_buf(int fd, char **buf, int *end);
char	*ft_check_if_newline(char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strncpy(char *dest, const char *src, size_t n);
int		ft_count_new_line(char **buf);

#endif
