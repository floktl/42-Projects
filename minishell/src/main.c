/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:03:04 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/17 14:49:26 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	prompt_loop(t_env **env_lst, t_tree	**parse_tree)
{
	int		debug_mode;
	char	*command;

	debug_mode = 0;
	command = NULL;
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
		if (parse_command(&command, env_lst, parse_tree) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (debug_mode)
			print_parse_tree(*parse_tree);
		execute_command(*parse_tree);
		//free_tree(*parse_tree, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_tree	*parse_tree;
	t_env	**env_lst;
	int		shell_status;

	(void)argc;
	(void)argv;
	env_lst = NULL;
	parse_tree = (t_tree *)malloc(sizeof(t_tree));
	if (!parse_tree)
		return (1);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	env_lst = init_env_list(envp);
	if (!env_lst)
		return (1);
	shell_status = prompt_loop(env_lst, &parse_tree);
	free_env_list(env_lst);
	clear_history();
	if (shell_status == EXIT_FAILURE)
		return (1);
	return (0);
}
