/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:47:36 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/31 22:33:00 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	function to read the user input from the terminal command

#define ESCAPE_SEQUENCE "\x1b"

//	count_arguments and remove quotes
int	adapt_and_count_arguments(t_tree *tree, char **cmd_str, int *ex_st)
{
	int	i;

	i = 1;
	(void)ex_st;
	tree->args = split_with_quotes(cmd_str, ' ', &i);
	tree->args_num = i;
	i = 0;
	if (tree->args == NULL)
		return (pipes_error("error split", tree, NULL));
	while (tree->args[i])
		i++;
	if (i > 0)
		tree->arrow_quote = ft_calloc(sizeof(int), 50);
	red_counter(tree, -1, 0);
	return (EXIT_SUCCESS);
}

//	function to split the commands into the components
int	split_command(t_tree *tree, char **command_str, int ex_st)
{
	if (null_term_string(command_str) == EXIT_FAILURE
		|| det_and_rem_quotes_first_word(*command_str) == EXIT_FAILURE
		|| adapt_and_count_arguments(tree, command_str, &ex_st) == EXIT_FAILURE
		|| expander(tree->args, tree->env, ex_st) == EXIT_FAILURE)
		return (ft_printf("error in parsing!\n"), EXIT_FAILURE);
	if (is_substr_first_word(*command_str, "echo"))
		tree->command = ECHO;
	else if (is_substr_first_word(*command_str, "pwd"))
		tree->command = PWD;
	else if (is_substr_first_word(*command_str, "cd"))
		tree->command = CD;
	else if (is_substr_first_word(*command_str, "env"))
		tree->command = ENV;
	else if (is_substr_first_word(*command_str, "unset"))
		tree->command = UNSET;
	else if (is_substr_first_word(*command_str, "export"))
		tree->command = EXPORT;
	else if (is_substr_first_word(*command_str, "exit"))
		tree->command = EXIT;
	tree->cmd_brch = ft_strdup(*command_str);
	if (!tree->cmd_brch)
		return (pipes_error("Error in strdup\n", tree, NULL));
	return (EXIT_SUCCESS);
}

int	add_node(t_tree **tree, t_tree **parent, char ***args, int *i)
{
	t_tree	*temp;

	temp = (t_tree *)malloc(sizeof(t_tree));
	if (!temp)
		return (pipes_error("error malloc", temp, *args));
	temp->parent_pipe = *parent;
	if (init_tree(temp, *args, (*tree)->exit_status, (*i)++) == -1)
		return (-1);
	if (temp->out_fd < 0)
	{
		(*tree)->out_fd = -1;
		if (!(*args)[*i])
		{
			(*tree)->exit_status = 1;
			free_parent_tree(tree);
			return (1);
		}
	}
	else
		ft_treeadd_back(tree, temp, parent);
	return (0);
}

int	add_node_red_err(t_tree **tree, t_tree **parent, char ***args, int *i)
{
	free_parent_tree(tree);
	if (init_tree(*tree, *args, (*tree)->exit_status, (*i)++) == -1)
		return (EXIT_FAILURE);
	parent = NULL;
	(void)parent;
	if ((*tree)->out_fd < 0)
	{
		if (!(*args)[*i])
		{
			free_tree(*tree);
			return (1);
		}
		if ((!(*tree)->args[1] || !(*tree)->args[1][0])
			&& ft_strncmp((*tree)->args[0], "cat", 3) == 0)
		{
			(*tree)->out_fd = -1;
			(*tree)->exit_status = 0;
			free_tree(*tree);
			if (!(*args)[*i] && !(*tree)->args[1])
				return (1);
		}
	}
	return (0);
}

//	function to seperate the pipes into the arguments and assign everything
int	build_command_tree(t_tree **tree, char *command_str, char **pipes, int i)
{
	t_tree	*parent;

	parent = *tree;
	if (!pipes || init_tree(*tree, pipes, (*tree)->exit_status, i++) == -1)
		return (pipes_error("error split", NULL, pipes));
	if ((*tree)->out_fd < 0 && !pipes[i])
	{
		free_parent_tree(tree);
		return (EXIT_SUCCESS);
	}
	while (pipes[i])
	{
		if ((*tree)->out_fd >= 0)
		{
			if (add_node(tree, &parent, &pipes, &i) == 1)
				return (EXIT_SUCCESS);
		}
		else
			if (add_node_red_err(tree, &parent, &pipes, &i) == 1)
				return (EXIT_SUCCESS);
	}
	return (free(command_str), EXIT_SUCCESS);
}
