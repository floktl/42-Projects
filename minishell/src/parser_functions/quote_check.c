/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:40:02 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/30 17:07:02 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	check if there are undisclosed quotes in the command string
int	check_for_quotes_and_slash(char *command_str)
{
	int	i;
	int	single_quote_counter;
	int	double_quote_counter;

	i = 0;
	single_quote_counter = 0;
	double_quote_counter = 0;
	while (command_str[i])
	{
		if (command_str[i] == '\"' && single_quote_counter % 2 == 0)
		{
			double_quote_counter++;
			single_quote_counter = 0;
		}
		else if (command_str[i] == '\'' && double_quote_counter % 2 == 0)
		{
			single_quote_counter++;
			double_quote_counter = 0;
		}
		if (command_str[i++] == '\x1C')
			remove_char(command_str, '\x1C', i, &i);
	}
	if (single_quote_counter % 2 != 0 || double_quote_counter % 2 != 0)
		return (ft_printf("undisclosed quote in command\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

//	checks, if string is in single or in double quote, returns 1 if not
int	both_quote_checker(char *arg, int j)
{
	static int	single_quote = 0;
	static int	double_quote = 0;

	if (j == 0)
	{
		single_quote = 0;
		double_quote = 0;
	}
	if (arg[j] && arg[j] == '\'' && !(double_quote))
	{
		single_quote = !(single_quote);
	}
	else if (arg[j] && arg[j] == '\"' && !(single_quote))
	{
		double_quote = !(double_quote);
	}
	if (single_quote || double_quote)
		return (0);
	return (1);
}

//	check if there are open quotes
int	check_for_open_quotes(char letter, int *s_quote, int *d_quote)
{
	if (letter == '\'' && !*s_quote)
	{
		if (*d_quote)
			return (EXIT_FAILURE);
		*s_quote = 1;
	}
	else if (letter == '\'' && *s_quote)
		*s_quote = 0;
	if (letter == '\"' && !*d_quote)
	{
		if (*s_quote)
			return (EXIT_FAILURE);
		*d_quote = 1;
	}
	else if (letter == '\"' && *d_quote)
		*d_quote = 0;
	return (EXIT_SUCCESS);
}

//	function to check for undisclosed quotes in the first word of a string
int	det_and_rem_quotes_first_word(char *command_str)
{
	int	i;
	int	s_quote;
	int	d_quote;

	i = 0;
	s_quote = 0;
	d_quote = 0;
	while (command_str[i] && command_str[i] == ' ')
		i++;
	while (command_str[i] && command_str[i] != ' ')
	{
		if (check_for_open_quotes(command_str[i], &d_quote, &s_quote)
			== EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (s_quote || d_quote)
		return (EXIT_FAILURE);
	if (is_substr_first_word(command_str, "<<") == 0)
	{
		remove_char(command_str, '\'', 0, &i);
		remove_char(command_str, '\"', 0, &i);
	}
	return (EXIT_SUCCESS);
}

//	function to remove single or double quotes form the arg string
int	remove_quotes(char **args, int i)
{
	static int	single_quote = 0;
	static int	double_quote = 0;
	int			j;

	j = 0;
	while (args[i][j])
	{
		if (args[i][j] == '\'' && !double_quote)
		{
			single_quote = !single_quote;
			rem_char(args[i], j);
			continue ;
		}
		else if (args[i][j] == '\"' && !single_quote)
		{
			double_quote = !double_quote;
			rem_char(args[i], j);
			continue ;
		}
		j++;
	}
	if (alloc_string(&args[i], ft_strlen(args[i])) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
