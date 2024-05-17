/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:47:36 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/17 14:07:11 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	initialize the command_tree struct
void	initiliaze_command_tree(t_tree *tree, int i, t_env **env_lst)
{
	tree->type = 0;
	tree->command = 0;
	tree->here_doc = NULL;
	tree->arguments = NULL;
	tree->cmd_brch = NULL;
	tree->child_pipe = NULL;
	tree->pipes_num = 0;
	tree->output = 0;
	tree->args_num = 0;
	tree->pipes_num = i + 1;
	tree->env = env_lst;
	tree->exit_status = 0;
}

//	function to parse the argument into parsing struct for cmd_exec funciton
int	parse_command(char **command_str, t_env **env_lst, t_tree **tree)
{

	add_history(*command_str);
	if (*command_str)
	{
		if (check_for_quotes_and_slash(*command_str) == EXIT_FAILURE)
		{
			free(*command_str);
			return (EXIT_FAILURE);
		}
		if (build_command_tree(tree, *command_str, env_lst) == EXIT_FAILURE)
		{
			free(*command_str);
			return (EXIT_FAILURE);
		}
	}
	free(*command_str);
	return (EXIT_SUCCESS);
}
