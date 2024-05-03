/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:03:04 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/01 14:18:05 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//	main loop start with  make and ./minishell
int	main(void)
{
	char	*command;
	t_tree	*parse_tree;

	signal(SIGINT, handle_signal);	// function to catch the signals
	while (1)
	{
		printf("$ ");
		fflush(stdout); //	verboten, muss nachher entfernt/ersetzt werden!
		command = ft_fgets();	// custum fgets function
		if (command == NULL)
		{
			printf("\n");
			break ;
		}
		if (command[0] && command[0] == '\n')
			continue ;
		if (strcmp(command, "exit") == 0)
		{
			free(command);
			break ;
		}
		parse_tree = parse_command(command); //	parsing function
		free(command);
		if (parse_tree == NULL)
			continue ;
		command = NULL;
		print_parse_tree(parse_tree);	// function to print tree struct values
		execute_command(parse_tree);	//	execution function
		free_tree(parse_tree);
	}
	delete_history();
	return (0);
}

//char	*args[MAX_ARGS];

	//command[strcspn(command, "\n")] = '\0';
	//g_history[g_history_count++] = strdup(command);
	//if (args[0] == NULL)
	//{
	//	continue ;
	//}
	//if (strcmp(args[0], "exit") == 0)
	//{
	//	break ;
	//}
	//if (strcmp(args[0], "history") == 0)
	//{
	//	while (i < g_history_count)
	//	{
	//		printf("%d: %s\n", i + 1, g_history[i]);
	//		i++;
	//	}
	//	continue ;
	//}
	//execute_command(args);

//while (i < g_history_count)
//{
//	free(g_history[i]);
//	i++;
//}
