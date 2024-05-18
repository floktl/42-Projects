/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:47:36 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/17 19:54:35 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	function to return an error string and free the tree and the array
int	pipes_error(char *errorstr, t_tree *tree, char **array)
{
	printf("%s\n", errorstr);
	free_two_dimensional_array(array);
	free_tree(tree);
	return (EXIT_FAILURE);
}
