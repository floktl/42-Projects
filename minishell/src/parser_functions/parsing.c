/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:47:36 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/31 22:23:18 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	initialize the command_tree struct
int	init_tree(t_tree *tree, char **pipes, int ex_st, int i)
{
	tree->type = 0;
	tree->command = 0;
	tree->here_doc = NULL;
	tree->args = NULL;
	tree->cmd_brch = NULL;
	tree->child_pipe = NULL;
	tree->pipes_num = 0;
	tree->output = 0;
	tree->args_num = 0;
	tree->in_fd = 0;
	tree->out_fd = 0;
	tree->pipes_num = i + 1;
	tree->arrow_quote = NULL;
	if (tree->parent_pipe)
	{
		tree->exit_status = ex_st;
		tree->env = tree->parent_pipe->env;
		tree->stdinput = tree->parent_pipe->stdinput;
		tree->stdoutput = tree->parent_pipe->stdoutput;
	}
	if (split_command(tree, &pipes[i], ex_st) == -1)
		return (pipes_error("error split_command", NULL, pipes));
	tree->args = handle_redirects(tree->args, tree);
	tree->parent_pipe = NULL;
	return (1);
}

//	function to parse the argument into parsing struct for cmd_exec funciton
int	parse_command(char **command_str, t_tree **tree)
{
	char	**pipes;
	int		pipes_num;

	add_history(*command_str);
	if (*command_str)
	{
		if (check_for_quotes_and_slash(*command_str) == EXIT_FAILURE)
		{
			free(*command_str);
			return (EXIT_FAILURE);
		}
		pipes = split_with_quotes(command_str, '|', &pipes_num);
		if (build_command_tree(tree, *command_str, pipes, 0) == EXIT_FAILURE)
		{
			free(*command_str);
			return (EXIT_FAILURE);
		}
		free_two_dimensional_array(pipes);
	}
	return (EXIT_SUCCESS);
}
