/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:47:36 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/25 22:08:12 by flo              ###   ########.fr       */
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
		line = ft_realloc(line, sizeof(char) * (len + 2));
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
int	adapt_arguments(t_tree *tree, char *command_str)
{
	int	i;
	//int	j;

	i = 0;
	// j = 0;
	while (command_str[i] && command_str[i] == ' ')
		i++;
	while (command_str[i])
	{
		if (command_str[i - 1] && command_str[i - 1] == ' ')
		{
			tree->args_num++;
			if (command_str[i] == '\'')
				return (EXIT_FAILURE);
			// while ()
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

//	function to split the commands into the components
int	split_command(t_tree *tree, char *command_str)
{
	// int	start_args;

	// start_args = 0;
	if (det_and_rem_quotes_first_word(command_str) == EXIT_FAILURE)
	{
		printf("undisclosed quotes in first word\n");
		return (EXIT_FAILURE);
	}
	// if (adapt_arguments(tree, command_str) == EXIT_FAILURE)
	// {
	// 	printf("Error removing whitespaces\n");
	// 	return (EXIT_FAILURE);
	// }
	if (is_substr_first_word(command_str, "echo"))
	{
		tree->type = EXEC;
		tree->command = ECHO;
		// if (check_for_flag(tree, command_str, 4) == EXIT_FAILURE)
		// {
		// 	free_tree(tree);
		// 	return (EXIT_FAILURE);
		// }
	}
	return (EXIT_SUCCESS);
}

//	function to seperate the pipe commands into single commands
int	seperate_pipes(t_tree *tree, char *command_str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	tree->cmd_brch = split_pipes(command_str, '|');
	if (tree->cmd_brch)
	{
		while (tree->cmd_brch[i])
		{
			temp = ft_strtrim(tree->cmd_brch[i], "|");
			if (!temp)
			{
				free_tree(tree);
				return (perror("ft_strtrim\n"), EXIT_FAILURE);
			}
			free(tree->cmd_brch[i]);
			tree->cmd_brch[i] = temp;
			printf("\"%s\"\n", tree->cmd_brch[i]);
			if (split_command(tree, tree->cmd_brch[i]) == EXIT_FAILURE)
			{
				ft_printf("split_command\n");
				free_tree(tree);
				return (EXIT_FAILURE);
			}
			i++;
		}
		tree->cmd_brch[i] = NULL;
	}
	return (EXIT_SUCCESS);
}
