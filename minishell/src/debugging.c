/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:36:56 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/15 16:31:57 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//	function to print the tree struct, only for debugging
void	print_parse_tree(const t_tree *tree)
{
	if (tree == NULL)
	{
		printf("\nt_parse_tree struct is Empty!\n");
		return ;
	}
	printf("\npipes_num: %d\nAdress: %p\n", tree->pipes_num, tree);
	if (tree->child_pipe)
		printf("childadress: %p\n", tree->child_pipe);
	if (tree->parent_pipe)
		printf("parentadress: %p\n", tree->parent_pipe);
	if (tree->type && tree->command)
		printf("type: %d\ncommand: %d\n", tree->type, tree->command);
	printf("arguments: ");
	if (tree->arguments != NULL)
		print_2d_array(tree->arguments);
	printf("\nargc: %d\ncmd_brch: ", tree->args_num);
	if (tree->cmd_brch)
		printf(":%s:", tree->cmd_brch);
	printf("\noutput: %d\n", tree->output);
	if (tree->child_pipe != NULL)
		print_parse_tree(tree->child_pipe);
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
