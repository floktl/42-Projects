/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:47:36 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/18 19:57:17 by flo              ###   ########.fr       */
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

//char *ft_fgets(void)
//{
//	struct termios	old_termios;
//	struct termios	new_termios;
//	char			*line;
//	size_t			len;
//	size_t			courser_pos;
//	int				c;
//	int				arrow_key;
//	//char			*temp;

//	line = NULL;
//	len = 0;
//	courser_pos = 0;
//	line = malloc(sizeof(char));
//	if (line == NULL)
//	{
//		perror("malloc");
//		return (NULL);
//	}
//	line[0] = '\0';
//	tcgetattr(STDIN_FILENO, &old_termios);
//	new_termios = old_termios;
//	new_termios.c_lflag &= ~(ICANON | ECHO);
//	tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
//	c = getchar();
//	while (c != '\n' && c != EOF)
//	{
//		if (c == 127)
//		{
//			if (len > 0 && courser_pos > 0)
//			{
//				printf("\b \b");
//				courser_pos--;
//				len--;
//				line[len] = '\0';
//			}
//		}
//		else if (c == '\b')
//		{
//			if (len > 0 && courser_pos > 0)
//			{
//				putchar('\b');
//				courser_pos--;
//				len--;
//			}
//		}
//		if (c == ESCAPE_SEQUENCE[0] && getchar() == '[')
//		{
//			arrow_key = getchar();
//			if (arrow_key == 'C')
//			{
//				if (courser_pos <= len + 1)
//				{
//					putchar(line[courser_pos]);
//					courser_pos++;
//				}
//			}
//			else if (arrow_key == 'D')
//			{
//				if (courser_pos > 0)
//				{
//					putchar('\b');
//					courser_pos--;
//				}
//			}
//			printf("%ld", courser_pos);
//		}
//		else
//		{
//			//temp = realloc(line, (len + 2) * sizeof(char));
//			//if (temp == NULL)
//			//{
//			//	free(line);
//			//	tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
//			//	perror("realloc");
//			//	return (NULL);
//			//}
//			//line = temp;
//			insert_char_at_position(line, (char)c, len, courser_pos);
//			//line[len++] = (char)c;
//			len++;
//			line[len] = '\0';
//			courser_pos++;
//			putchar(c);
//		}
//		c = getchar();
//	}
//	printf("\nlen: %ld courser: %ld\n", len, courser_pos);
//	printf("\n");
//	tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
//	return (line);
//}

// int main() {
//     printf("Enter text: ");
//     char *input = ft_fgets();
//     if (input != NULL) {
//         printf("You entered: %s\n", input);
//         free(input);
//     }
//     return 0;
// }

//	count_arguments and remove quotes
int	adapt_and_count_arguments(t_tree *tree, char *command_str)
{
	int	i;

	i = 1;
	tree->arguments = split_pipes(command_str, ' ', &i);
	tree->args_num = i;
	return (EXIT_SUCCESS);
}

//int	search_for_variable_in_env(char *variable, char **envp)
//{
//	char	*replace;
//	int		i;
//	int		j;
//	int		temp;

//	i = 0;
//	while (envp[i])
//	{
//		j = 1;
//		while (envp[i][j] && variable[i] && envp[i][j + 1] == variable[1])
//		{
//			j++;
//		}
//		if (envp[i][j] && envp[i][j + 1] &&  envp[i][j] == '=')
//		{
//			j++;
//			j = temp;
//			while (envp[i][temp])
//			{
//				temp++;
//			}
//			free(variable);
//			variable = ft_substr(envp[i], j, temp - 1);
//			return (0);
//		}
//	}
//	return (1);
//}

//int main() {
//    // Allocate memory for the environment variables array
//    char **envp = (char **)malloc(7 * sizeof(char *));
//    if (envp == NULL) {
//        perror("Memory allocation failed");
//        return 1;
//    }

//    // Set environment variables
//    envp[0] = strdup("HOSTNAME=e3d678c4e42d");
//    envp[1] = strdup("PWD=/dorker_workspace/miniiii/minishell");
//    envp[2] = strdup("HOME=/root");
//    envp[3] = strdup("TERM=xterm");
//    envp[4] = strdup("SHLVL=1");
//    envp[5] = strdup("PATH=/usr/local/sbin:/usr/l=");
//    envp[6] = strdup("OLDPWD=/dorker_workspace/miniiii");

//    // Test the search_for_variable_in_env function
//    char *variable = strdup("PWD");
//    int result = search_for_variable_in_env(variable, envp);
//    if (result == 0) {
//        printf("Variable found: %s\n", variable);
//    } else {
//        printf("Variable not found\n");
//    }

//    // Free allocated memory
//    for (int i = 0; i < 7; i++) {
//        free(envp[i]);
//    }
//    free(envp);

//    free(variable); // Don't forget to free the variable allocated by strdup

//    return 0;
//}

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
	if (export_dollar_sign(tree->arguments, tree->env, tree->exit_status)
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

	parent = NULL;
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
			parent = *tree;
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

