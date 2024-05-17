/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:09:19 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/12 08:07:16 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	function to count the pipes with checking for single and double quotes
void	count_pipes(char const *s, char pipe, int *pipe_num)
{
	int	i;
	int	d_quote;
	int	s_quote;

	i = 0;
	d_quote = 0;
	s_quote = 0;
	while (s[i])
	{
		if (s[i] == '\"' && s_quote % 2 == 0)
		{
			d_quote++;
			s_quote = 0;
		}
		else if (s[i] == '\'' && d_quote % 2 == 0)
		{
			s_quote++;
			d_quote = 0;
		}
		else if (s[i] == pipe && s_quote % 2 == 0 && d_quote % 2 == 0)
			*pipe_num += 1;
		i++;
	}
}

int	quote_check(const char *s, int *pipe_len, char pipe, int *i)
{
	static int	doub_quo = 0;
	static int	sing_quo = 0;

	if (s[*i] == '\"' && sing_quo % 2 == 0)
	{
		doub_quo++;
		sing_quo = 0;
	}
	else if (s[*i] == '\'' && doub_quo % 2 == 0)
	{
		sing_quo++;
		doub_quo = 0;
	}
	else if (s[*i] == pipe && sing_quo % 2 == 0 && doub_quo % 2 == 0)
	{
		sing_quo = 0;
		return (doub_quo = 0, 1);
	}
	if (!s[(*i) + 1])
	{
		sing_quo = 0;
		doub_quo = 0;
	}
	*pipe_len += 1;
	return (*i += 1, 0);
}

//	function to assign the pipes into two dimensional array accordance of quotes
int	assign_pipes(char const *s, char pipe, char **split, int pipes)
{
	int	i;
	int	count;
	int	pipe_len;

	i = 0;
	count = 0;
	while (s[i] && count < pipes)
	{
		while (s[i] && s[i] == pipe)
			i++;
		pipe_len = 0;
		while (s[i] && s[i] == ' ')
			i++;
		while (s[i] && quote_check(s, &pipe_len, pipe, &i) == 0)
			continue ;
		if (pipe_len > 0)
		{
			split[count] = ft_substr(s, i - pipe_len, pipe_len);
			if (!split[count])
				return (ft_free(split, count), EXIT_FAILURE);
			count++;
		}
	}
	split[count] = NULL;
	return (EXIT_SUCCESS);
}

char	**split_pipes(char const *s, char c, int *pipe_num)
{
	char	**split;

	if (!s)
		return (NULL);
	*pipe_num = 1;
	count_pipes(s, c, pipe_num);
	split = ft_calloc(*pipe_num + 1, sizeof(char *));
	if (!split)
		return (NULL);
	if (assign_pipes(s, c, split, *pipe_num) == EXIT_FAILURE)
	{
		return (NULL);
	}
	return (split);
}
