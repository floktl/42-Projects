/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:40:02 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/25 22:07:19 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	check if there are undisclosed quotes int he command string
int	check_for_quotes(t_tree *tree, char *command_str)
{
	int	i;
	int	single_quote_counter;
	int	double_quote_counter;

	(void)tree;
	i = 0;
	single_quote_counter = 0;
	double_quote_counter = 0;
	while (command_str[i])
	{
		if (command_str[i] == '\'')
			single_quote_counter++;
		if (command_str[i] == '\"')
			double_quote_counter++;
		i++;
	}
	if (single_quote_counter % 2 != 0 || double_quote_counter % 2 != 0)
	{
		printf("undisclosed quote in command\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

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
	remove_char(command_str, '\'', 0, i);
	remove_char(command_str, '\"', 0, i);
	return (EXIT_SUCCESS);
}
