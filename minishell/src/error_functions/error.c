/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:47:36 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/10 12:54:06 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	function to return an error string and free the tree and the array
int	pipes_error(char *errorstr, t_tree *tree, char **array)
{
	ft_printf("%s\n", errorstr);
	(void)array;
	free_two_dimensional_array(array);
	free_tree(&tree);
	return (EXIT_FAILURE);
}

void	print_str_return_exit(char *str, int exit_code, t_tree *tree)
{
	dup2(2, 1);
	ft_printf(" %s", str);
	dup2(tree->stdoutput, 1);
	tree->exit_status = exit_code;
}

void	print_exit(char *message, char *argument, int errorcode, void *to_free)
{
	dup2(2, 1);
	ft_printf("%s: %s\n", argument, message);
	if (to_free)
		free(to_free);
	exit (errorcode);
}
