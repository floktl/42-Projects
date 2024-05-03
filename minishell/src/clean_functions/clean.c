/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:49:29 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/26 19:37:09 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	function to free the entire parsing tree
void	free_tree(t_tree *parse_tree)
{
	if (!parse_tree)
		return ;
	if (parse_tree->cmd_brch)
	{
		free(parse_tree->cmd_brch);
		parse_tree->cmd_brch = NULL;
	}
	if (parse_tree->flags)
	{
		free_two_dimensional_array(parse_tree->flags);
	}
	if (parse_tree->args_num)
	{
		free_two_dimensional_array(parse_tree->arguments);
	}
	if (parse_tree->child_pipe)
		free_tree(parse_tree->child_pipe);
	free(parse_tree);
	parse_tree = NULL;
}

//	function to free an two dimensional array
void	ft_free(char **split, int words)
{
	while (words > 0)
	{
		if (split[words - 1])
			free(split[words - 1]);
		words--;
	}
	free(split);
}
