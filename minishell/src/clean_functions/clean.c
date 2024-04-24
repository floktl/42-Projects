/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:49:29 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/22 18:40:12 by fkeitel          ###   ########.fr       */
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
		free_two_dimensional_array(parse_tree->cmd_brch);
	}
	if (parse_tree->flags)
	{
		free_two_dimensional_array(parse_tree->flags);
	}
	
	free(parse_tree);
	parse_tree = NULL;
}
