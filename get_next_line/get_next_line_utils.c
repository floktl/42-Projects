/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:42:50 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/25 11:27:38 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	counter;
	char	*char_b;

	counter = 0;
	char_b = (char *)b;
	if (len == 0)
		return (b);
	while (counter <= len - 1)
	{
		char_b[counter++] = c;
	}
	b = char_b;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	str = malloc(count * size);
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, count * size);
	return (str);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*((char *)(dst + i)) = *((char *)(src + i));
			i++;
		}
	}
	return (dst);
}

char	*ft_check_if_newline(char *s)
{
	int	counter;

	counter = 0;
	while (s[counter++] != '\n' && s[counter] != '\0')
	{
		if (s[counter] == '\n')
			return (s);
	}
	return (NULL);
}

char	*double_bufsize_fill_with_null(const char *s1)
{
	size_t	old_size;
	size_t	new_size;
	char	*conc_str;

	if (!s1)
		return (NULL);
	old_size = ft_strlen(s1);
	new_size = old_size + BUFFER_SIZE + 1;
	conc_str = ft_calloc(new_size, 1);
	if (!conc_str)
		return (NULL);
	ft_strncpy(conc_str, s1, old_size);
	return (conc_str);
}

void	*extract_line(char **line, char **buf, int *end)
{
	int	i;
	int	len;

	i = ft_count_new_line(buf);
	len = i;
	if ((*buf)[i - 1] == '\n' || ((*buf)[i - 1] == '\0' && (*buf)[0] != 0))
	{
		if ((*buf)[i - 1] == '\0')
			len--;
		*line = malloc(sizeof(char) * (len + 1));
		if (!(*line))
			return (free(buf), NULL);
		ft_strncpy(*line, *buf, i);
		if ((*buf)[i - 1] == '\n')
		{
			(*line)[i] = '\0';
			ft_memmove(*buf, *buf + i, *end - i + 1);
			*end -= i;
			(*buf)[*end] = '\0';
		}
		else
			*end = 0;
	}
	return (*line);
}
