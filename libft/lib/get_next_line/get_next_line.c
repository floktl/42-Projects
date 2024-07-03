/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:01:46 by stopp             #+#    #+#             */
/*   Updated: 2024/06/28 17:07:12 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include "../../../minishell.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*nstr;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 && !s2)
		return (NULL);
	nstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (nstr == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		nstr[i] = s1[i];
	j = 0;
	while (s2[j])
		nstr[i++] = s2[j++];
	free (s1);
	nstr[i] = '\0';
	return (nstr);
}

char	*rd_to_str(int fd, char *str)
{
	char	*buf;
	int		bytes;

	if (read(fd, 0, 0) < 0)
		return (free(str), NULL);
	buf = malloc((BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	bytes = 1;
	while (ft_strchr(str, '\n') == NULL && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buf);
			free (str);
			return (NULL);
		}
		buf[bytes] = '\0';
		str = ft_strjoin_gnl(str, buf);
		if (str == NULL)
			return (NULL);
	}
	free (buf);
	return (str);
}

char	*get_line1(char *str)
{
	int		i;
	char	*new_line;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	new_line = malloc(sizeof(char) * (i + 1));
	if (new_line == NULL)
		return (NULL);
	new_line[i] = '\0';
	while (--i >= 0)
		new_line[i] = str[i];
	return (new_line);
}

char	*update_str(char *str)
{
	int		i;
	int		j;
	char	*updated;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	if (str[i] == '\n')
		i++;
	updated = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (updated == NULL)
		return (free(str), NULL);
	j = 0;
	while (str[i])
		updated[j++] = str[i++];
	updated[j] = '\0';
	free (str);
	return (updated);
}

/**
 * Function to return one line from the given file descriptor
 *
 * @param fd The file descriptor to read the file from
 * @return One line from the file descriptor, until '\n' or '\0'
 */
char	*get_next_line(int fd)
{
	static char	*str;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = rd_to_str(fd, str);
	if (str == NULL)
		return (NULL);
	if (*str == '\0')
	{
		free (str);
		str = NULL;
		return (NULL);
	}
	next_line = get_line1(str);
	str = update_str(str);
	if (str == NULL)
		return (next_line);
	return (next_line);
}

// int main(int argc, char *argv[])
// {
// 	int fd = open(argv[1], O_RDONLY);
// 	printf("next line: %s", get_next_line(fd));
// 	printf("next line: %s", get_next_line(fd));
// 	printf("next line: %s", get_next_line(fd));
// 	printf("next line: %s", get_next_line(fd));
// 	close (fd);
// 	return (0);
// }
