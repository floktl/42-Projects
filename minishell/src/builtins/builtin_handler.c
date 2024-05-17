/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:15:21 by stopp             #+#    #+#             */
/*   Updated: 2024/05/15 18:07:52 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handle_builtins(t_tree *tree, t_env **env_lst)
{
	int		fd[2];
	int		booli;

	booli = 0;
	if (tree->child_pipe)
	{
		if (pipe(fd) == -1)
			return ;
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		booli = 1;
	}
	if (tree->command == ECHO)
		ft_echo(tree);
	if (tree->command == PWD)
		ft_pwd();
	if (tree->command == CD)
		ft_chdir(tree, env_lst);
	if (booli)
	{
		dup2(fd[0], STDIN_FILENO);
		close (fd[0]);
	}
}
