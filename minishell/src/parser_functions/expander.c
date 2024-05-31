/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:38:16 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/31 22:30:46 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	function to check for quotes in the env and fills the strings
int	check_for_quotes(char **replace, t_env *envp, char **var, char *arg)
{
	int		j;

	j = 0;
	while (envp->name[j] && *arg && arg[j] && envp->name[j] == arg[j])
		(j)++;
	if (!envp->name[j] && (!arg[j] || (arg[j] && (arg[j] == ' '
					|| arg[j] == '\'' || arg[j] == '\"' || arg[j] == '$'
					|| arg[j] == '<' || arg[j] == '>'))))
	{
		*var = malloc(sizeof(char) * (ft_strlen(envp->name) + 2));
		if (!(*var))
			return (-1);
		(*var)[0] = '$';
		ft_strlcpy(*var + 1, envp->name, ft_strlen(envp->name) + 1);
		*replace = ft_strdup(envp->value);
		if (!(*replace))
			return (free(*var), -1);
		return (1);
	}
	return (0);
}

//	this function searches for a variable in the environment and saves in var
int	find_var_in_env(char **replace, t_env *envp, char *arg, char **var)
{
	t_env	*temp;
	int		quote_check;
	int		j;

	*var = NULL;
	j = 1;
	if (!arg || (arg && arg[0] != '$')
		|| (arg[1] && (arg[1] == ' ' || arg[1] == '\"')) || !arg[1])
		return (0);
	temp = envp;
	while (temp)
	{
		quote_check = check_for_quotes(replace, temp, var, arg + 1);
		if (quote_check != 0)
			return (quote_check);
		temp = temp->next;
	}
	while (arg[j] && arg[j] && arg[j] != ' ' && arg[j] != '$'
		&& arg[j] != '\"' && arg[j] != '\'')
		j++;
	if (j > 0)
		return (create_var_and_rep_str(var, replace, arg, j));
	return (1);
}

//	expand the exit status when argument is $?
int	exit_expander(char **arg, int j, int ex_st)
{
	char	*exit_string;
	char	*dollar;

	if ((*arg)[j + 1] && (*arg)[j] == '$' && (*arg)[j + 1] == '?')
	{
		exit_string = ft_itoa(ex_st);
		if (!exit_string)
			return (EXIT_FAILURE);
		dollar = ft_strdup("$?");
		if (!dollar)
			return (free(exit_string), EXIT_FAILURE);
		if (replace_substr(arg, &dollar, exit_string, j) == -1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

//	function to expand the tilde symbol, when not in quotes
int	tilde_expander(char **arg, int j)
{
	char	*var;
	char	*replace;

	if (both_quote_checker(*arg, j) && (*arg)[j] == '~'
		&& (!(*arg)[j + 1]
		|| (((*arg)[j + 1]) == ' ' || ((*arg)[j + 1]) == '/')))
	{
		var = ft_strdup("~");
		if (!var)
			return (EXIT_FAILURE);
		replace = ft_strdup(getenv("HOME"));
		if (!var)
			return (free(var), EXIT_FAILURE);
		if (replace_substr(arg, &var, replace, j) == -1)
		{
			free(var);
			free(replace);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

//	function to convert the argument into the string
int	expander(char **args, t_env **env, int ex_st)
{
	char	*var;
	char	*rep;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			if (tilde_expander(&args[i], j) == EXIT_FAILURE
				|| (quote_checker(args[i], j) && args[i][j] == '$'
				&& (exit_expander(&args[i], j, ex_st) == EXIT_FAILURE
					|| find_var_in_env(&rep, *env, args[i] + j, &var) == -1
					|| replace_substr(&args[i], &var, rep, j) == -1)))
				return (EXIT_FAILURE);
			j++;
		}
		if (remove_quotes(args, i++) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
