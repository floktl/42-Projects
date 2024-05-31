/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:15:21 by stopp             #+#    #+#             */
/*   Updated: 2024/05/31 21:36:43 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	update_exit(t_tree *tree, int exec_exit)
{
	if (WIFEXITED(tree->exit_status))
		tree->exit_status = WEXITSTATUS(tree->exit_status);
	if (tree->exit_status > 1 && exec_exit != 0)
		tree->exit_status += 128;
}

int	exit_handler(t_tree *tree)
{
	int	i;

	i = 0;
	if (tree->pipes_num == 1)
		ft_printf("exit\n");
	if (tree->args[1])
	{
		while (tree->args[1][i])
		{
			if (*tree->args[1] != 45 && (!ft_isdigit(tree->args[1][i])
				&& tree->args[1][i] != '+'))
			{
				return (print_str_return_exit
					("numeric argument required\n", 255, tree));
			}
			i++;
		}
		if (tree->args[2])
		{
			tree->command = 0;
			return (print_str_return_exit("too many arguments\n", 1, tree));
		}
		tree->exit_status = ft_atoi(tree->args[1]) % 256;
	}
	return (tree->exit_status);
}

void	execute_builtin(t_tree *tree, t_env **env_lst)
{
	open_close_fds(tree);
	if (tree->command == ECHO)
		ft_echo(tree);
	else if (tree->command == PWD)
		ft_pwd(tree);
	else if (tree->command == CD)
		ft_chdir(tree, env_lst);
	else if (tree->command == ENV)
		print_env(tree);
	else if (tree->command == UNSET)
	{
		if (!tree->args[1])
			ft_unset(tree, NULL);
		else
			ft_unset(tree, ft_strdup(tree->args[1]));
	}
	else if (tree->command == EXPORT)
	{
		if (!tree->args[1])
			export_env(tree);
		else
			export(tree, ft_strdup(tree->args[1]));
	}
}

pid_t	exec_pipe(t_tree *tree, t_env **env_lst, int *exec_exit)
{
	pid_t		pid;
	int			fd[2];

	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		close(fd[0]);
		if (tree->child_pipe)
			dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		*exec_exit = 1;
		execute_builtin(tree, env_lst);
		exit (0);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close (fd[0]);
	}
	return (pid);
}

pid_t	handle_builtins(t_tree *tree, t_env **env_lst, int *exec_exit)
{
	pid_t	pid;

	pid = 0;
	if (tree->child_pipe || tree->parent_pipe)
		pid = exec_pipe(tree, env_lst, exec_exit);
	else
	{
		execute_builtin(tree, env_lst);
		if (tree->command == EXIT)
		{
			tree->exit_status = exit_handler(tree);
			if (tree->command == EXIT && !tree->child_pipe
				&& !tree->parent_pipe)
				tree->signal_exit = 1;
		}
	}
	return (pid);
}
