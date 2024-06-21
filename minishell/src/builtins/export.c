/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:06:36 by stopp             #+#    #+#             */
/*   Updated: 2024/06/09 18:03:45 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	export_err(char *name, t_tree *tree)
{
	tree->exit_status = 1;
	dup2(2, 1);
	ft_printf("export : %s: not a valid identifier\n", name);
	dup2(tree->stdoutput, 1);
	free(name);
	return (0);
}

int	name_check(char *tmp, t_tree *tree)
{
	char	*name;

	name = tmp;
	if (ft_isalpha(*name) == 1 || *name == '_')
		name++;
	else
		return (export_err(tmp, tree));
	while (*name)
	{
		if (*name == '=')
			return (1);
		if (ft_isalnum(*name) == 1 || *name == '_')
			name++;
		else
			return (export_err(tmp, tree));
	}
	return (1);
}

void	export(t_tree *tree, char *new_env)
{
	t_env	*tmp;
	t_env	*new;

	if (!new_env)
		return ;
	tmp = *(tree->env);
	if (name_check(new_env, tree) == 0)
		return ;
	new = init_node(new_env);
	if (!new)
		return (free(new_env));
	free(new_env);
	while (tmp)
	{
		if (ft_strncmp(tmp->name, new->name, ft_strlen(tmp->name)) == 0)
		{
			free(tmp->value);
			tmp->value = new->value;
			free(new->name);
			free(new);
			return ;
		}
		tmp = tmp->next;
	}
	lstadd_back_env(tree->env, new);
}

void	export_env(t_tree *tree)
{
	t_env	*env;

	env = *tree->env;
	while (env)
	{
		ft_printf("declare -x %s=\"%s\"\n", env->name, env->value);
		env = env->next;
	}
}

void	export_loop(t_tree *tree)
{
	int	i;

	i = 1;
	if (!tree->args[i])
		export_env(tree);
	else
	{
		while (tree->args[i])
			export(tree, ft_strdup(tree->args[i++]));
	}
}
