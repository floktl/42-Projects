/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/05/15 18:06:29 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../minishell.h"

t_env	*init_node(char *envp)
{
	int		i;
	int		j;
	t_env	*env;

	i = 0;
	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	while (envp[i] != '=' && envp[i])
		i++;
	env->name = malloc(i + 1);
	if (!env->name)
		return (NULL);
	ft_strlcpy(env->name, envp, i + 1);
	j = i + 1;
	while (envp[i])
		i++;
	env->value = malloc(i - j + 1);
	if (!env->name)
		return (NULL);
	ft_strlcpy(env->value, &envp[j], i - j + 1);
	env->next = NULL;
	return (env);
}

void	lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*current;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
}

t_env	**init_env_list(char **envp)
{
	int		i;
	t_env	**env_lst;
	t_env	*env;

	i = 0;
	env = NULL;
	env_lst = malloc(sizeof(t_env *));
	if (!env_lst)
		return (NULL);
	i++;
	*env_lst = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "OLDPWD=", 7) != 0)
		{
			env = init_node(envp[i]);
			if (!env)
				return (NULL);
			lstadd_back_env(env_lst, env);
		}
		i++;
	}
	return (env_lst);
}

// void	print_list(t_env *env_list)
// {
// 	while (env_list)
// 	{
// 		printf("%s=%s\n", env_list->name, env_list->value);
// 		env_list = env_list->next;
// 	}
// }
