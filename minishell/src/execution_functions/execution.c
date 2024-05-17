/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:47:36 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/15 17:49:45 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_getenv(t_env **env_lst, char *name)
{
	t_env	*tmp;

	tmp = *env_lst;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, name, ft_strlen(name)) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

char	**get_paths(t_env **env_lst)
{
	int		i;
	char	*path;
	char	**paths;

	i = 0;
	path = ft_getenv(env_lst, "PATH");
	if (path)
	{
		paths = ft_split(path, ':');
		if (!paths)
			return (0);
		while (paths[i])
		{
			path = paths[i];
			paths[i] = ft_strjoin(path, "/");
			free(path);
			if (!paths[i])
				return (NULL);
			i++;
		}
		return (paths);
	}
	else
		return (NULL);
}

char	*get_cmdpath(char *cmd, t_env **env_lst)
{
	int		i;
	char	*cmd_path;
	char	**paths;

	i = 0;
	paths = get_paths(env_lst);
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

int	join_name_value(t_env *env_node, char **env_array, int i)
{
	char	*tmp;

	tmp = ft_strjoin(env_node->name, "=");
	if (!tmp)
		return (0);
	env_array[i] = ft_strjoin(tmp, env_node->value);
	if (!env_array[i])
		return (free(tmp), 0);
	free (tmp);
	return (1);
}

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

void	exec_cmd(t_tree *tmp, t_env **env_lst)
{
	char	*cmdpath;
	char	**env_array;

	cmdpath = get_cmdpath(tmp->arguments[0], env_lst);
	env_array = create_env_array(*env_lst);
	if (!env_array)
		exit (1);
	if (tmp->arguments[0] == ft_strchr(tmp->arguments[0], '/'))
		execve(tmp->arguments[0], tmp->arguments, env_array);
	else
		execve(cmdpath, tmp->arguments, env_array);
	perror("execution failed");
	exit (1);
}

int	pipe_cmds(t_tree *tmp, t_env **env_lst)
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
		exec_cmd(tmp, env_lst);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	return (1);
}

void	execute_command(t_tree *tree)
{
	t_tree	*tmp;
	int		stdin2;
	int		stdout2;

	tmp = tree;
	stdin2 = dup(STDIN_FILENO);
	stdout2 = dup(STDOUT_FILENO);
	while (tmp)
	{
		if (tmp->command)
			handle_builtins(tmp, tmp->env);
		else
			pipe_cmds(tmp, tmp->env);
		if (tmp->child_pipe)
			dup2(stdout2, STDOUT_FILENO);
		tmp = tmp->child_pipe;
	}
	dup2(stdin2, STDIN_FILENO);
	wait(NULL);
	return ;
}
