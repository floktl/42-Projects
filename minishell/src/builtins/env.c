/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:44:52 by stopp             #+#    #+#             */
/*   Updated: 2024/05/31 21:37:59 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_env(t_tree *tree)
{
	char	*path;

	path = ft_getenv(*(tree->env), "PATH");
	if (!path)
	{
		dup2(2, 1);
		ft_printf("env: No such file or directory\n");
		dup2(tree->stdoutput, 1);
		tree->exit_status = 127;
	}
	else
	{
		print_list(*tree->env);
		free(path);
		tree->exit_status = 0;
	}
}
