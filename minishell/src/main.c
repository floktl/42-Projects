/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:03:04 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/10 18:53:25 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_synerror(char *c, char *cmd, t_tree *tree)
{
	dup2(2, 1);
	ft_printf("syntax error near unexpected token: `%s'\n", c);
	dup2(tree->stdoutput, 1);
	tree->exit_status = 2;
	free(cmd);
}

int	check_syntax(t_tree *tree, char *cmd, int j)
{
	while (j >= 0)
	{
		if (cmd[j] == '|')
			return (print_synerror("|", cmd, tree), 0);
		else if (ft_isprint(cmd[j]) == 1)
			break ;
		j--;
	}
	return (1);
}

int	chk_syntax(char *cmd, t_tree *tree)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*cmd == '|')
		return (print_synerror("|", cmd, tree), 0);
	while (cmd[i])
	{
		if (both_quote_checker(cmd, i) == 1)
		{
			if ((cmd[i] == '<' || cmd[i] == '>')
				&& (cmd[i + 1] == '\0' || cmd[i + 1] == '\n'))
				return (print_synerror("newline", cmd, tree), 0);
			if (cmd[i] == '|')
			{
				j = i - 1;
				if (check_syntax(tree, cmd, j) == 0)
					return (0);
			}
		}
		i++;
	}
	return (1);
}

int	prompt_loop(t_tree	**parse_tree)
{
	char	*command;

	rl_catch_signals = 0;
	command = NULL;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_handler);
	while ((*parse_tree)->signal_exit == 0)
	{
		command = readline("\033[32mminishell> \033[0m");
		if (command == NULL)
			return ((*parse_tree)->exit_status);
		signal(SIGINT, SIG_IGN);
		if (chk_syntax(command, *parse_tree) == 0)
			continue ;
		if (parse_command(&command, parse_tree) == EXIT_FAILURE)
			exit ((*parse_tree)->exit_status);
		if ((*parse_tree)->out_fd < 0)
		{
			free(command);
			continue ;
		}
		execute_command(*parse_tree);
		free_tree(parse_tree);
	}
	return ((*parse_tree)->exit_status);
}

int	main(int argc, char **argv, char **envp)
{
	t_tree	*parse_tree;
	int		shell_status;

	(void)argc;
	(void)argv;
	parse_tree = (t_tree *)malloc(sizeof(t_tree));
	if (!parse_tree)
		return (1);
	parse_tree->exit_status = 0;
	parse_tree->signal_exit = 0;
	parse_tree->stdinput = dup(STDIN_FILENO);
	parse_tree->stdoutput = dup(STDOUT_FILENO);
	parse_tree->env = init_env_list(envp);
	parse_tree->parent_pipe = NULL;
	parse_tree->out_fd = parse_tree->stdoutput;
	if (!parse_tree->env)
		return (free(parse_tree->env), 1);
	shell_status = prompt_loop(&parse_tree);
	free_env_list(parse_tree->env);
	free(parse_tree);
	clear_history();
	return (shell_status);
}

//int	prompt_loop(t_tree	**parse_tree)
//{
//	int		debug_mode;
//	char	*command;

//	rl_catch_signals = 0;
//	debug_mode = 0;
//	command = NULL;
//	add_history("cat << a");
//	signal(SIGQUIT, SIG_IGN);
//	signal(SIGINT, signal_handler);
//	while ((*parse_tree)->signal_exit == 0)
//	{
//		command = readline("\033[32mminishell> \033[0m");
//		if (command == NULL)
//		{
//			if (command)
//				free(command);
//			return ((*parse_tree)->exit_status);
//		}
//		if (strcmp(command, "deb") == 0)
//		{
//			debug_mode = !debug_mode;
//			free(command);
//			continue ;
//		}
//		signal(SIGINT, SIG_IGN);
//		if (parse_command(&command, parse_tree) == EXIT_FAILURE)
//			exit ((*parse_tree)->exit_status);
//		if ((*parse_tree)->out_fd < 0)
//		{
//			free(command);
//			continue ;
//		}
//		if (debug_mode)
//			print_parse_tree(*parse_tree);
//		execute_command(*parse_tree);
//		free_tree(*parse_tree);
//	}
//	return ((*parse_tree)->exit_status);
//}
