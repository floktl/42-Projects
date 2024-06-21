/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:46:57 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/02 20:19:09 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	red_counter(t_tree *tree, int z, int counter)
{
	int	quote_checker;
	int	j;

	while (tree->args[++z])
	{
		j = 0;
		while (tree->args[z][j])
		{
			quote_checker = both_quote_checker(tree->args[z], j);
			if (tree->args[z][j] == '>' || tree->args[z][j] == '<')
			{
				if (quote_checker == 1)
					tree->arrow_quote[counter++] = 1;
				else if (quote_checker == 0)
					tree->arrow_quote[counter++] = 0;
				j++;
				if (tree->args[z][j] && (tree->args[z][j] == '>'
						|| tree->args[z][j] == '<'))
					j++;
			}
			else
				j++;
		}
	}
}

char	*exec_cmd_funct(char **cmd_str, t_tree *tree, int *i, t_cmd_func func)
{
	*cmd_str = func(*cmd_str, tree);
	*i = 0;
	return (*cmd_str);
}

int	prep_redec(char **args, int j, t_tree *tree, t_cmd_func func)
{
	char	*to_free;

	to_free = NULL;
	if (args[0][j] == args[0][j + 1])
	{
		j++;
	}
	if (args && args[0] && args[0][j + 1])
		args[0] = func(args[0], tree);
	else if (args && args[0])
	{
		to_free = args[0];
		args[0] = ft_strjoin(args[0], args[1]);
		if (!args[0])
			return (-1);
		args[1][0] = '\0';
		free(to_free);
		args[0] = func(args[0], tree);
	}
	return (1);
}

int	check_for_redirections(t_tree *tree, char ***args, int i, int j)
{
	static int	z = 0;

	if (i == 0 && j == 0)
		z = 0;
	if (((*args)[i][j] == '>' || (*args)[i][j] == '<')
		&& tree->arrow_quote[z++] == 1
		&& ((ft_strncmp(&(*args)[i][j], "<<", 2) == 0
		&& (*args)[i][j + 2] != '<' && ((*args)[i][j + 2] || (*args)[i + 1])
		&& prep_redec(&(*args)[i--], j, tree, handle_heredoc))
		|| (ft_strncmp(&(*args)[i][j], ">>", 2) == 0
		&& (*args)[i][j + 2] != '>' && (((*args)[i][j + 2] || (*args)[i + 1]))
		&& prep_redec(&(*args)[i--], j, tree, handle_append))
		|| (ft_strncmp(&(*args)[i][j], ">", 1) == 0
		&& (*args)[i][j + 1] != '>' && ((*args)[i][j + 1] || (*args)[i + 1])
		&& prep_redec(&(*args)[i--], j, tree, handle_trunc))
		|| (ft_strncmp(&(*args)[i][j], "<", 1) == 0
		&& (*args)[i][j + 1] != '<' && ((*args)[i][j + 1] || (*args)[i + 1])
		&& prep_redec(&(*args)[i--], j, tree, handle_infile))))
		return (1);
	else
		return (0);
}

//	function to handle all redirecton cases from the command string
char	**handle_redirects(char **args, t_tree *tree)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		j = -1;
		while (args[i][++j])
		{
			if (check_for_redirections(tree, &args, i, j) == 1)
			{
				i = update_args(&args);
				break ;
			}
			if (tree->out_fd < 0)
				return (free_two_dimensional_array(args), NULL);
		}
		if (i >= 0)
			i++;
		else
			i = 0;
	}
	return (update_args(&args), args);
}
