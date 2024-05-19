/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:47:36 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/19 00:02:00 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	function to read the user input from the terminal command
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define ESCAPE_SEQUENCE "\x1b"

char	*insert_char_at_position(char *s, char c, size_t len, size_t pos)
{
	char	*new_s;

	new_s = malloc((len + 2) * sizeof(char));
	if (new_s == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	ft_strncpy(new_s, s, pos);
	new_s[pos] = c;
	strcpy(new_s + pos + 1, s + pos);
	return (new_s);
}

//	count_arguments and remove quotes
int	adapt_and_count_arguments(t_tree *tree, char *command_str)
{
	int	i;

	i = 1;
	tree->arguments = split_pipes(command_str, ' ', &i);
	tree->args_num = i;
	return (EXIT_SUCCESS);
}

//	function to save the heredoc input in a string
int	handle_here_doc(t_tree *tree)
{
	(void)tree;
	return (EXIT_SUCCESS);
}

//	function to split the commands into the components
int	split_command(t_tree *tree, char *command_str)
{
	if (det_and_rem_quotes_first_word(command_str) == EXIT_FAILURE
		|| adapt_and_count_arguments(tree, command_str) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (expander(tree->arguments, tree->env, tree->exit_status)
		== EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (is_substr_first_word(command_str, "echo"))
	{
		tree->type = EXEC;
		tree->command = ECHO;
	}
	if (is_substr_first_word(command_str, "pwd"))
	{
		tree->type = EXEC;
		tree->command = PWD;
	}
	if (is_substr_first_word(command_str, "cd"))
	{
		tree->type = EXEC;
		tree->command = CD;
	}
	tree->cmd_brch = ft_strdup(command_str);
	if (!tree->cmd_brch)
	{
		printf("Error in strdup\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

//	function to seperate the pipes into the arguments and assign everything
int build_command_tree(t_tree **tree, char *command_str)
{
	int pipe_num;
	char **pipes;
	t_tree *temp;
	t_tree *parent;

	parent = *tree;
	pipes = split_pipes(command_str, '|', &pipe_num);
	if (!pipes)
		return (pipes_error("error split", NULL, pipes));
	pipe_num = 0;
	while (pipes[pipe_num])
	{
		if (pipe_num == 0)
		{
			initiliaze_command_tree(*tree, pipe_num);
			if (split_command(*tree, pipes[pipe_num]) == EXIT_FAILURE)
				return (pipes_error("error split_command", *tree, pipes));
		}
		else
		{
			temp = (t_tree *)malloc(sizeof(t_tree));
			if (!temp)
				return (pipes_error("error malloc", temp, pipes));
			temp->parent_pipe = parent;
			initiliaze_command_tree(temp, pipe_num);
			if (split_command(temp, pipes[pipe_num]) == EXIT_FAILURE)
				return (pipes_error("error split_command", temp, pipes));
			ft_treeadd_back(tree, temp, &parent);
		}
		pipe_num++;
	}
	free_two_dimensional_array(pipes);
	return (EXIT_SUCCESS);
}

