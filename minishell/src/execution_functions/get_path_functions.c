/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:57:40 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/31 21:25:06 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_getenv(t_env *env_lst, char *name)
{
	t_env	*tmp;

	tmp = env_lst;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, name, ft_strlen(tmp->name)) == 0)
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
	path = ft_getenv(*env_lst, "PATH");
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

char	*get_cmdpath(char *cmd, t_env **env_lst, t_tree *tree)
{
	int		i;
	char	*cmd_path;
	char	**paths;

	i = 0;
	paths = get_paths(env_lst);
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (access(cmd_path, F_OK) == 0)
		{
			if (access(cmd_path, X_OK) == 0)
				return (free_two_dimensional_array(paths), cmd_path);
			else
			{
				dup2(2, 1);
				ft_printf("%s: Permission denied\n", tree->args[0]);
				exit (126);
			}
		}
		free(cmd_path);
		i++;
	}
	free_two_dimensional_array(paths);
	return (NULL);
}

void	print_exit(char *message, char *argument, int errorcode, void *to_free)
{
	dup2(2, 1);
	ft_printf("%s: %s\n", argument, message);
	if (to_free)
		free(to_free);
	exit (errorcode);
}

void	absolute_path(t_tree *tmp, char **env_array)
{
	DIR	*dir;

	dir = opendir((tmp->args[0]));
	if (dir)
		print_exit("is a directory", tmp->args[0], 126, dir);
	else if (access(tmp->args[0], F_OK) == 0)
	{
		if (access(tmp->args[0], X_OK) == 0)
			execve(tmp->args[0], tmp->args, env_array);
		else
			print_exit("Permission denied", tmp->args[0], 126, NULL);
	}
	else
		print_exit("No such file or directory", tmp->args[0], 127, NULL);
}
