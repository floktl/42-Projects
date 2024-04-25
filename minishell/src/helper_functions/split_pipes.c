/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:09:19 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/25 12:29:46 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	char	*temp_sub_s;
	size_t	count;
	size_t	count_sub;
	size_t	size_s;

	size_s = strlen(s);
	if (len > size_s)
		len = size_s;
	sub_s = (char *)calloc(len + 1, sizeof(char));
	if (!sub_s)
		return (NULL);
	count_sub = 0;
	count = 0;
	temp_sub_s = sub_s;
	while (s[count] && count_sub < len)
	{
		if (count >= start)
		{
			*sub_s++ = s[count];
			count_sub++;
		}
		count++;
	}
	return (temp_sub_s);
}

static void	ft_free(char **split, size_t words)
{
	while (words > 0)
	{
		if (split[words - 1])
			free(split[words - 1]);
		words--;
	}
	free(split);
}

size_t	count_pipes(char const *s, char c)
{
	size_t i = 0;
	size_t count = 0;
	int undisclosed_quote = 0;

	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			if (undisclosed_quote == 0)
				count++;
			while (s[i] && s[i] != c)
			{
				if (s[i] == '\"')
					undisclosed_quote = !undisclosed_quote;
				i++;
			}
		}
		else
		{
			if (s[i] == '\"')
				undisclosed_quote = !undisclosed_quote;
			i++;
		}
	}
	return (count);
}

void	ft_progress(char const *s, char c, char **split, size_t words)
{
	size_t	i;
	size_t	pipe_len;
	size_t	count;
	int		in_quotes;

	i = 0;
	count = 0;
	in_quotes = 0;
	while (s[i] && count < words)
	{
		pipe_len = 0;
		while (s[i] == c && s[i])
		{
			i++;
		}
		if (s[i] == '\"')
		{
			in_quotes = !in_quotes;
		}
		while (s[i] && (s[i] != c || in_quotes))
		{
			if (s[i] == '\"' && in_quotes)
			{
				in_quotes = 0;
			}
			pipe_len++;
			i++;
		}
		if (pipe_len > 0)
		{
			split[count] = ft_substr(s, i - pipe_len, pipe_len);
			if (!split[count])
			{
				ft_free(split, count);
				return ;
			}
			count++;
		}
	}
	split[count] = NULL;
}

char	**split_pipes(char const *s, char c)
{
	char	**split;
	size_t	pipes;

	if (!s)
		return (NULL);
	pipes = count_pipes(s, c);
	printf("\n%ld\n", pipes);
	split = calloc(pipes + 1, sizeof(char *));
	if (!split)
		return (NULL);
	ft_progress(s, c, split, pipes);
	return (split);
}

int main()
{
	char const *input = "0 \"| 0\"";

	char **result = split_pipes(input, '|');

	if (result)
	{
		printf("Split result:\n");
		for (size_t i = 0; result[i] != NULL; i++)
		{
			printf("[%zu]: \"%s\"\n", i, result[i]);
		}
		for (size_t i = 0; result[i] != NULL; i++)
		{
			free(result[i]);
		}
		free(result);
	}
	else
	{
		printf("Error: Memory allocation failed.\n");
	}
	return 0;
}
