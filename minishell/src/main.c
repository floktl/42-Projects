/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:03:04 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/18 19:59:55 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	prompt_loop(t_tree	**parse_tree)
{
	int		debug_mode;
	char	*command;

	debug_mode = 0;
	command = NULL;
	add_history(" echo hello | echo hello");
	while (1)
	{
		command = readline("\033[32mminishell> \033[0m");
		if (command == NULL || !ft_strncmp(command, "exit", 4))
		{
			if (command)
				free(command);
			return (EXIT_SUCCESS);
		}
		if (command[0] == '\0')
		{
			free(command);
			continue ;
		}
		if (strcmp(command, "deb") == 0)
		{
			debug_mode = !debug_mode;
			free(command);
			continue ;
		}
		if (parse_command(&command, parse_tree) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (debug_mode)
			print_parse_tree(*parse_tree);
		execute_command(*parse_tree);
		free_tree(*parse_tree);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_tree	*parse_tree;
	int		shell_status;

	(void)argc;
	(void)argv;
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	parse_tree = (t_tree *)malloc(sizeof(t_tree));
	if (!parse_tree)
		return (1);
	parse_tree->exit_status = 0;
	parse_tree->env = init_env_list(envp);
	parse_tree->parent_pipe = NULL;
	if (!parse_tree->env)
		return (free(parse_tree->env), 1);
	shell_status = prompt_loop(&parse_tree);
	free_env_list(parse_tree->env);
	free(parse_tree);
	clear_history();
	if (shell_status == EXIT_FAILURE)
		return (1);
	return (0);
}
