/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:36:56 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/28 11:59:26 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//	function to print the tree struct, only for debugging
void	print_parse_tree(const t_tree *tree)
{
	printf("\n");
	if (tree == NULL)
	{
		printf("t_parse_tree struct is NULL\n");
		return ;
	}
	printf("pipes_num: %d\n", tree->pipes_num);
	printf("Adress: %p\n", tree);
	if (tree->child_pipe)
		printf("childadress: %p\n", tree->child_pipe);
	if (tree->parent_pipe)
		printf("parentadress: %p\n", tree->parent_pipe);
	if (tree->type && tree->command)
	{
		printf("type: %d\n", tree->type);
		printf("command: %d\n", tree->command);
	}
	if (tree->flags != NULL)
	{
		printf("flags: ");
		print_2d_array(tree->flags);
	}
	printf("arguments: ");
	if (tree->arguments != NULL)
	{
		print_2d_array(tree->arguments);
	}
	printf("\nargc: %d", tree->args_num);
	printf("\ncmd_brch: ");
	if (tree->cmd_brch)
	{
		printf(":%s:", tree->cmd_brch);
	}
	printf("\n");
	printf("output: %d\n", tree->output);
	printf("\n");
	if (tree->child_pipe != NULL)
	{
		print_parse_tree(tree->child_pipe);
	}
}

//	print two-dimensional array
void	print_2d_array(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i] != NULL)
	{
		j = 0;
		printf("%d: [", i);
		while (array[i][j] != '\0')
		{
			printf("%c", array[i][j]);
			j++;
		}
		printf("] ");
		i++;
	}
}
