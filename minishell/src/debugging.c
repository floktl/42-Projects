/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:36:56 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/24 12:47:19 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void print_parse_tree(const t_tree *tree)
{
	printf("\n");
    if (tree == NULL) {
        printf("t_parse_tree struct is NULL\n");
        return;
    }
	if (tree->type && tree->command)
	{
		printf("type: %d\n", tree->type);
		printf("command: %d\n", tree->command);
	}

    printf("flags: ");
    if (tree->flags != NULL) {
        char **flag = tree->flags;
        while (*flag != NULL) {
            printf("%s ", *flag);
            flag++;
        }
    }
    printf("\n");

    printf("arguments: ");
    if (tree->arguments != NULL) {
        char **arg = tree->arguments;
        while (*arg != NULL) {
            printf("%s ", *arg);
            arg++;
        }
    }
    printf("\ncmd_brch: ");
    if (tree->cmd_brch) {
        char **cmd = tree->cmd_brch;
		int i = 0;
        while (cmd[i] != NULL) {
            printf("%d: %s ", i,  cmd[i]);
            i++;
        }
    }
    printf("\n");
	if (tree->output && tree->pipes_num)
	{
		printf("output: %d\n", tree->output);
		printf("pipes_num: %d\n", tree->pipes_num);
	}

    // You need to define the struct t_cmd and its members to print parsed_command

    printf("\n");
}
