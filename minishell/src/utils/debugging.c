/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:36:56 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/06 16:53:08 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	function to print the tree struct, only for debugging
void	print_parse_tree(const t_tree *tree)
{
	if (tree == NULL)
	{
		ft_printf("\nt_parse_tree struct is Empty!\n");
		return ;
	}
	ft_printf("\npipes_num: %d\nAdress: %p\n", tree->pipes_num, tree);
	if (tree->child_pipe)
		ft_printf("childadress: %p\n", tree->child_pipe);
	if (tree->parent_pipe)
		ft_printf("parentadress: %p\n", tree->parent_pipe);
	if (tree->type && tree->command)
		ft_printf("type: %d\ncommand: %d\n", tree->type, tree->command);
	ft_printf("arguments: ");
	if (tree->args != NULL)
		print_2d_array(tree->args);
	ft_printf("\nargc: %d\ncmd_brch: ", tree->args_num);
	if (tree->cmd_brch)
		ft_printf(":%s:", tree->cmd_brch);
	ft_printf("\noutput: %d\n", tree->output);
	ft_printf("out_fd: %d\n", tree->out_fd);
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
		ft_printf("%d: [", i);
		while (array[i][j] != '\0')
		{
			ft_printf("%c", array[i][j]);
			j++;
		}
		ft_printf("] ");
		i++;
	}
}
