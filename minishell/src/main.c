/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:03:04 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/24 19:34:02 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*g_history[MAX_HISTORY];
int		g_history_count = 0;

int	main(void)
{
	char	*command;
	//int		i;
	t_tree	*parse_tree;

	//i = 0;
	signal(SIGINT, handle_signal);
	while (1)
	{
		printf("$ ");
		fflush(stdout);
		command = ft_fgets();
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
		parse_tree = parse_command(command);
		free(command);
		print_parse_tree(parse_tree);
		free_tree(parse_tree);
		//i++;
	}
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
