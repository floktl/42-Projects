/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:09:19 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/24 23:05:38 by flo              ###   ########.fr       */
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

static size_t	count_pipes(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		undisclosed_quote;

	i = 0;
	count = 0;
	undisclosed_quote = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
		{
			if (s[i] == '\"')
				undisclosed_quote = !undisclosed_quote;
			i++;
		}
		if (s[i] && s[i] == '\"')
				undisclosed_quote = !undisclosed_quote;
		if (s[i] && s[i] != c && !undisclosed_quote)
		{
			count++;
			while (s[i] && s[i] != c)
			{
				i++;
				if (s[i] && s[i] == '\"')
					undisclosed_quote = !undisclosed_quote;
			}
		}
		else
		{
			i++;
			if (s[i] && s[i] == '\"')
					undisclosed_quote = !undisclosed_quote;
		}
	}
	printf("%d\n", undisclosed_quote);
	return (count);
}

static void ft_progress(char const *s, char c, char **split, size_t words) {
    size_t i = 0;
    size_t word_len;
    size_t count = 0;
    int in_quotes = 0; // Flag to track whether inside quotes

    while (s[i] && count < words) {
        word_len = 0;

        // Skip leading delimiters
        while (s[i] == c && s[i]) {
            i++;
        }

        // Check if inside quotes
        if (s[i] == '\"') {
            in_quotes = !in_quotes;
            i++;
        }

        // Process word
        while (s[i] && (s[i] != c || in_quotes)) {
            // Check for closing quote
            if (s[i] == '\"' && in_quotes) {
                in_quotes = 0; // Toggle quotes off
            }
            word_len++;
            i++;
        }

        // Allocate memory for word
        if (word_len > 0) {
            split[count] = ft_substr(s, i - word_len, word_len);
            if (!split[count]) {
                ft_free(split, count);
                return;
            }
            count++;
        }
    }

    // Terminate split array
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
	char const *input = "this is a test |\" test2 | \"test3  | test5\" | test\"";

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
