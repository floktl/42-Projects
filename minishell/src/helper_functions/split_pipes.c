/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:09:19 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/25 16:01:36 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_sub_str(char const *s, unsigned int start, int len)
{
	char	*sub_s;
	char	*temp_sub_s;
	int		count;
	int		count_sub;
	int		size_s;

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

static void	ft_free(char **split, int words)
{
	while (words > 0)
	{
		if (split[words - 1])
			free(split[words - 1]);
		words--;
	}
	free(split);
}

int	count_pipes(char const *s, char c)
{
	int i = 0;
	int count = 0;
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

void assign_pipes(char const *s, char pipe, char **split, int words)
{
	int i = 0;
	int count = 0;
	int in_quotes = 0;
	int pipe_len;

	while (s[i] && count < words)
	{
		while (s[i] == pipe && s[i])
			i++;
		pipe_len = 0;
		while (s[i] && s[i] == ' ')
			i++;
		while (s[1])
		{
			if (s[i] == '\"')
			{
				in_quotes = !in_quotes;
			}
			if (s[i] == pipe && !in_quotes)
			{
				break ;
			}
			pipe_len++;
			i++;
		}
		if (pipe_len > 0)
		{
			
			split[count] = ft_sub_str(s, i - pipe_len, pipe_len);
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
	int		pipes;

	if (!s)
		return (NULL);
	pipes = count_pipes(s, c);
	printf("\n%d\n", pipes);
	split = calloc(pipes + 1, sizeof(char *));
	if (!split)
		return (NULL);
	assign_pipes(s, c, split, pipes);
	return (split);
}

int main()
{
	char const *input = "echo \"test | test\" | echo test";

	char **result = split_pipes(input, '|');

	if (result)
	{
		printf("Split result:\n");
		for (int i = 0; result[i] != NULL; i++)
		{
			printf("[%d]: \"%s\"\n", i, result[i]);
		}
		for (int i = 0; result[i] != NULL; i++)
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
