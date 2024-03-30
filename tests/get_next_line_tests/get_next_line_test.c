/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:40:04 by fkeitel           #+#    #+#             */
/*   Updated: 2023/11/11 15:19:19 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1

size_t	ft_strlen(const char *c)
{
	size_t	counter;

	counter = 0;
	while (c[counter] != '\0')
		counter++;
	return (counter);
}

char	*double_bufsize_fill_with_null(char const *s1)
{
	char	*conc_str;
	int		counter;
	int		counter_2;

	counter = 0;
	counter_2 = 0;
	conc_str = NULL;
	conc_str = malloc((int)ft_strlen(s1) * 2 + 1);
	if (!conc_str)
		return (NULL);
	while (s1[counter_2] != '\0')
	{
		conc_str[counter_2] = s1[counter_2];
		counter_2++;
	}
	while (counter <= counter_2)
	{
		conc_str[counter + counter_2] = '\0';
		counter++;
	}
	return (conc_str);
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

void	*extract_line_from_buf(char **line, char **buf, int *end)
{
	int	i;

	i = 1;
	while ((*buf)[i - 1] != '\n' && (*buf)[i - 1] != '\0' && **buf)
		i++;
	if ((*buf)[i - 1] == '\n' || ((*buf)[i - 1] == '\0' && (*buf)[0] != 0))
	{
		*line = malloc(i + 1);
		if (!(*line))
			return (NULL);
		if ((*buf)[i - 1] == '\n')
		{
			strncpy(*line, *buf, i);
			(*line)[i] = '\0';
			ft_memmove(*buf, *buf + i, *end);
			*end -= i;
		}
		else
		{
			strcpy(*line, *buf);
			*end = 0;
		}
		(*buf)[*end] = '\0';
	}
	return (*line);
}

int	read_and_update_buf(int fd, char **buf, int *end)
{
	int		read_bytes;
	char	*new_buf;
	int		len_old;

	new_buf = NULL;
	len_old = 0;
	while (*buf[0] == '\0' || (*end != 0 && *buf[0] != '\0'))
	{
		if (*end != 0)
		{
			new_buf = double_bufsize_fill_with_null(*buf);
			len_old = ft_strlen(*buf);
			free(*buf);
			*buf = NULL;
			if (!new_buf)
				return (-1);
			*buf = new_buf;
			read_bytes = read(fd, *buf + len_old, BUFFER_SIZE);
		}
		if (read_bytes == -1)
			return (-1);
		else if (read_bytes == 0)
			break ;
		*end += read_bytes;
		if (strchr(*buf, '\n') )
			break ;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	static int	end;

	line = NULL;
	if (fd < 0)
		return (NULL);
	if (!buf)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		buf[0] = '\0';
	}
	if (read_and_update_buf(fd, &buf, &end) == -1)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	if (extract_line_from_buf(&line, &buf, &end) == NULL)
	{
		free(buf);
		buf = NULL;
	}
	return (line);
}

int	main()
{
	int		file_descriptor;
	FILE	*fptr;
	char	content[1000];
	char	*line;

	file_descriptor = open("test.txt", O_RDONLY);
	while ((line = get_next_line(file_descriptor)) != NULL)
		printf("%s", line);
	free(line);
	close(file_descriptor);
	return (0);
}
