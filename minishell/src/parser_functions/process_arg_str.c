/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:47:36 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/24 14:47:46 by fkeitel          ###   ########.fr       */
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

int	count_flags(const char *str, int start, char c)
{
	int	count;
	int	i;

	count = 0;
	i = start;
	while (str[i])
	{
		if (str[i] == c)
		{
			count++;
		}
		i++;
	}
	return (count);
}

//	check if there are any flags in the command string
int	check_for_flag(t_tree *tree, char *cmd_str, int start)
{
	int		i;
	char	**flags;
	int		fl_l;
	int		fl_c;

	i = start;
	fl_c = 0;
	flags = NULL;
	int flag_num = count_flags(cmd_str, start, '-');
	if (flag_num > 0)
	{
		flags = (char **)malloc(sizeof(char *) * (flag_num + 1));
		if (!flags)
		{
			free_two_dimensional_array(flags);
			perror("malloc");
			return (EXIT_FAILURE);
		}
		flags[flag_num] = NULL;
		flags[0] = (char *)malloc((sizeof(char)) * 2);
		while (cmd_str[i] && flag_num > 0)
		{
			while (cmd_str[i] && cmd_str[i] == ' ')
				i++;
			if (cmd_str[i] && cmd_str[i - 1] == ' ' && cmd_str[i] == '-')
			{
				flags[fl_c][0] = '-';
				flags[fl_c][1] = '\0';
				fl_l = 1;
				i++;
				while (cmd_str[i] && cmd_str[i] != ' ' && cmd_str[i] != '\n')
				{
					flags[fl_c] = (char *)realloc(flags[fl_c], (sizeof(char)) * (fl_l + 2));
					if (!flags[fl_c])
					{
						free_two_dimensional_array(flags);
						perror("malloc");
						return (EXIT_FAILURE);
					}
					flags[fl_c][fl_l++] = cmd_str[i];
					i++;
				}
				flags[fl_c][fl_l] = '\0';
				fl_c++;
				flag_num--;
			}
			else
				i++;
		}
	}
	tree->flags = flags;
	return (EXIT_SUCCESS);
}

//	check if there are undisclosed quotes int he command string
int	check_for_quotes(t_tree *tree, char *command_str)
{
	(void)tree;
	int	i;
	int	single_quote_counter;
	int	double_quote_counter;

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

//	function to check for undisclosed quotes in the first word of a string
int	det_and_rem_quotes_first_word(char *command_str)
{
	int	i;
	int	open_single_quote;
	int	open_double_quote;

	i = 0;
	open_single_quote = 0;
	open_double_quote = 0;
	while (command_str[i] && command_str[i] == ' ')
		i++;
	while (command_str[i] && command_str[i] != ' ')
	{
		if (command_str[i] == '\'' && !open_single_quote)
		{
			if (open_double_quote)
				return (EXIT_FAILURE);
			open_single_quote = 1;
		}
		else if (command_str[i] == '\'' && open_single_quote)
			open_single_quote = 0;
		if (command_str[i] == '\"' && !open_double_quote)
		{
			if (open_single_quote)
				return (EXIT_FAILURE);
			open_double_quote = 1;
		}
		else if (command_str[i] == '\"' && open_double_quote)
			open_double_quote = 0;
		i++;
	}
	if (open_single_quote || open_double_quote)
		return (EXIT_FAILURE);
	remove_char(command_str, '\'', 0, i);
	remove_char(command_str, '\"', 0, i);
	return (EXIT_SUCCESS);
}

//	count_arguments and remove quotes
int	adapt_arguments(t_tree *tree, char *command_str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (command_str[i] && command_str[i] == ' ')
		i++;
	while (command_str[i])
	{
		if (command_str[i - 1] && command_str[i - 1] == ' ')
		{
			tree->args_num++;
			if (command_str[i] == '\'')
				
		}
	}
	return (EXIT_SUCCESS);
}

//	function to split the commands into the components
int	split_command(t_tree *tree, char *command_str)
{
	int	start_args;

	start_args = 0;
	if (det_and_rem_quotes_first_word(command_str, &start_args) == EXIT_FAILURE)
	{
		printf("undisclosed quotes in first word\n");
		return (EXIT_FAILURE);
	}
	if (adapt_arguments(tree, command_str) == EXIT_FAILURE)
	{
		printf("Error removing whitespaces\n");
		return (EXIT_FAILURE);
	}
	if (is_substr_first_word(command_str, "echo"))
	{
		tree->type = EXEC;
		tree->command = ECHO;
		//if (check_for_flag(tree, command_str, 4) == EXIT_FAILURE)
		//{
		//	free_tree(tree);
		//	return (EXIT_FAILURE);
		//}
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
	tree->cmd_brch = ft_split(command_str, '|');
	if (tree->cmd_brch)
	{
		while (tree->cmd_brch[i])
		{
			temp = ft_strtrim(tree->cmd_brch[i], "|");
			if (!temp)
			{
				perror("ft_strtrim");
				free_tree(tree);
				return (EXIT_FAILURE);
			}
			free(tree->cmd_brch[i]);
			tree->cmd_brch[i] = temp;
			printf("\"%s\"\n", tree->cmd_brch[i]);
			if (split_command(tree, tree->cmd_brch[i]) == EXIT_FAILURE)
			{
				ft_printf("split_command");
				free_tree(tree);
				return (EXIT_FAILURE);
			}
			i++;
		}
		tree->cmd_brch[i] = NULL;
	}
	return (EXIT_SUCCESS);
}
