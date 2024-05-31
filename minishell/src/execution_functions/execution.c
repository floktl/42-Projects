/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:47:36 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/31 21:24:54 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**create_env_array(t_env *env_lst)
{
	int		i;
	t_env	*tmp;
	char	**env_array;

	i = 0;
	tmp = env_lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	env_array = malloc(sizeof(char *) * (i + 1));
	if (!env_array)
		return (NULL);
	env_array[i] = NULL;
	tmp = env_lst;
	i = 0;
	while (tmp)
	{
		if (!join_name_value(tmp, env_array, i++))
			return (NULL);
		tmp = tmp->next;
	}
	return (env_array);
}

void	open_close_fds(t_tree *tree)
{
	if (tree->out_fd != 0)
	{
		dup2(tree->out_fd, STDOUT_FILENO);
		close (tree->out_fd);
	}
	if (tree->in_fd != 0)
	{
		dup2(tree->in_fd, STDIN_FILENO);
		close (tree->in_fd);
	}
}

void	exec_cmd(t_tree *tmp, t_env **env_lst)
{
	char	*cmdpath;
	char	**env_array;

	env_array = create_env_array(*env_lst);
	signal(SIGINT, signal_handle);
	signal(SIGQUIT, signal_handle);
	if (!env_array)
		exit (1);
	if (tmp->args[0] == ft_strchr(tmp->args[0], '/')
		|| ft_strncmp(tmp->args[0], "./", 2) == 0)
		absolute_path(tmp, env_array);
	else
	{
		cmdpath = get_cmdpath(tmp->args[0], env_lst, tmp);
		if (!cmdpath)
		{
			dup2(2, 1);
			ft_printf("%s: command not found\n", tmp->args[0]);
			exit (127);
		}
		open_close_fds(tmp);
		execve(cmdpath, tmp->args, env_array);
		exit(1);
	}
}

pid_t	pipe_cmds(t_tree *tmp, t_env **env_lst, int *exec_exit)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		close(fd[0]);
		if (tmp->child_pipe)
			dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		*exec_exit = 1;
		exec_cmd(tmp, env_lst);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	return (pid);
}

//	execution function
void	execute_command(t_tree *tree)
{
	t_tree	*tmp;
	pid_t	pid;
	int		exec_exit;

	tmp = tree;
	pid = 0;
	exec_exit = 0;
	while (tmp)
	{
		if (tmp->args[0] && tree->out_fd >= 0)
		{
			if (tmp->command > 0)
				pid = handle_builtins(tmp, tmp->env, &exec_exit);
			else
				pid = pipe_cmds(tmp, tmp->env, &exec_exit);
			if (tmp->child_pipe)
				dup2(tree->stdoutput, STDOUT_FILENO);
		}
		tmp = tmp->child_pipe;
	}
	waitpid(pid, &tree->exit_status, 0);
	dup2(tree->stdinput, STDIN_FILENO);
	dup2(tree->stdoutput, STDOUT_FILENO);
	update_exit(tree, exec_exit);
	signal(SIGINT, signal_handler);
}
