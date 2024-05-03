/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:47:36 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/28 11:30:03 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	function to read the user input from the terminal command
char	*ft_fgets(void)
{
	struct termios	old_termios;
	struct termios	new_termios;
	char			*line;
	size_t			len;
	int				c;

	line = NULL;
	len = 0;
	tcgetattr(STDIN_FILENO, &old_termios);
	new_termios = old_termios;
	new_termios.c_lflag &= ~(ICANON);
	tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
	c = getchar();
	while (c != '\n' && c != EOF)
	{
		line = realloc(line, sizeof(char) * (len + 2));
		if (line == NULL)
		{
			free(line);
			tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
			return (perror("realloc"), NULL);
		}
		line[len++] = (char)c;
		line[len] = '\0';
		c = getchar();
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
	return (line);
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

//	function to split the commands into the components
int	split_command(t_tree *tree, char *command_str)
{
	if (det_and_rem_quotes_first_word(command_str) == EXIT_FAILURE)
	{
		printf("undisclosed quotes in first word\n");
		return (EXIT_FAILURE);
	}
	if (adapt_and_count_arguments(tree, command_str) == EXIT_FAILURE)
	{
		printf("Error in arguments\n");
		return (EXIT_FAILURE);
	}
	if (is_substr_first_word(command_str, "echo"))
	{
		tree->type = EXEC;
		tree->command = ECHO;
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
int	build_command_tree(t_tree **tree, char *command_str)
{
	int		pipe_num;
	char	**pipes;
	t_tree	*temp;
	t_tree	*parent;

	parent = NULL;
	pipes = split_pipes(command_str, '|', &pipe_num);
	pipe_num = 0;
	if (pipes)
	{
		while (pipes[pipe_num])
		{
			temp = (t_tree *)malloc(sizeof(t_tree));
			if (!temp)
				return (pipes_error("error malloc", temp, pipes));
			initiliaze_command_tree(temp, pipe_num);
			if (split_command(temp, pipes[pipe_num++]) == EXIT_FAILURE)
				return (pipes_error("error split_command", temp, pipes));
			ft_treeadd_back(tree, temp, &parent);
		}
		free_two_dimensional_array(pipes);
	}
	else
		return (pipes_error("error split", NULL, pipes));
	return (EXIT_SUCCESS);
}
