/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:34:22 by stopp             #+#    #+#             */
/*   Updated: 2024/05/16 15:26:25 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	export(t_tree *tree, char *new_env)
{
	t_env	*tmp;
	t_env	*new;

	tmp = *tree->env;
	new = init_node(new_env);
	free(new_env);
	while (tmp)
	{
		if (ft_strncmp(tmp->name, new->name, ft_strlen(new->name) == 0))
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

void	change_to_parent(t_tree *tree)
{
	int		i;
	char	*curr_dir;
	char	*new_dir;

	curr_dir = getcwd(NULL, 0);
	i = ft_strlen(curr_dir);
	while (curr_dir[i] != '/')
		i--;
	export(tree, ft_strjoin("OLDPWD=", curr_dir));
	new_dir = ft_calloc(i + 1, 1);
	ft_strlcpy(new_dir, curr_dir, i + 1);
	chdir(new_dir);
	free(curr_dir);
	free(new_dir);
	return ;
}

void	ft_chdir(t_tree *tree, t_env **env_lst)
{
	//t_env	*tmp;

	//tmp = *env_lst;
	(void)env_lst;
	if (tree->arguments[2] != NULL)
		ft_printf("cd: string not in pwd: %s\n", tree->arguments[1]);
	if (ft_strncmp(tree->arguments[1], "..", 3) == 0)
		change_to_parent(tree);
	// else if (ft_strncmp(tree->arguments[1], "-", 2) == 0)
	// 	change_to_previous(tmp);
	// else if (ft_strncmp(tree->arguments[1], "~", 2) == 0)
	// 	change_to_home(tmp);
	// else if (ft_strncmp(tree->arguments[1], ".", 2) == 0)
	// 	return ;
	// else
	// 	change_dir;
}
