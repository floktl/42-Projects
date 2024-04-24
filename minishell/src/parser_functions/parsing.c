/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:47:36 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/24 14:36:27 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	initialize the command_tree struct
void	initiliaze_command_tree(t_tree *tree)
{
	tree->type = 0;
	tree->command = 0;
	tree->flags = NULL;
	tree->arguments = NULL;
	tree->arguments = 0;
	tree->cmd_brch = NULL;
	tree->parent_pipe = NULL;
	tree->child_pipe = NULL;
	tree->pipes_num = 0;
	tree->parsed_command = NULL;
	tree->output = 0;
}

//	function to parse the argument into parsing struct for  cmd exec funciton
t_tree	*parse_command(char *command_str)
{
	t_tree	*tree;

	tree = malloc(sizeof(t_tree));
	if (!tree)
	{
		perror("malloc");
		return (NULL);
	}
	initiliaze_command_tree(tree);
	if (command_str)
	{
		if (check_for_quotes(tree, command_str) == EXIT_FAILURE)
		{
			free_tree(tree);
			return (NULL);
		}
		if (seperate_pipes(tree, command_str) == EXIT_FAILURE)
		{
			perror("seperating pipes");
			return (NULL);
		}
	}
	return (tree);
}
