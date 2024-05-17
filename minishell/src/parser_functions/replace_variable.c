/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:38:16 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/17 12:56:12 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	function to check for quotes in the env and fills the strings
int	check_for_quotes(char **s, char *envp, char **var, int *j)
{
	char	*new_str;
	size_t	len;

	*j = 0;
	while (envp[*j] && (*s)[*j + 1] && envp[*j] == (*s)[*j + 1])
		(*j)++;
	if (envp[*j] && envp[*j] == '=' && (!(*s)[*j + 1] || ((*s)[*j + 1]
		&& ((*s)[*j + 1] == ' ' || (*s)[*j + 1] == '\''
		|| (*s)[*j + 1] == '\"' || (*s)[*j + 1] == '$'))))
	{
		free(*var);
		*var = malloc(sizeof(char) * (*j + 2));
		ft_strlcpy(*var, *s, *j + 2);
		len = strlen(envp + ++(*j));
		new_str = ft_substr(envp, *j, len);
		if (new_str != NULL)
		{
			free(*s);
			*s = ft_strdup(new_str);
			return (free(new_str), 1);
		}
		free(*var);
		return (0);
	}
	return (-1);
}

//	this function searches for a variable in the environment and saves in var
int	search_for_var_in_env(char **s, char **envp, char *arg, char **var)
{
	int		i;
	int		j;
	int		quote_check;

	*s = strdup(arg);
	*var = strdup(*s);
	i = -1;
	while (envp[++i])
	{
		quote_check = check_for_quotes(s, envp[i], var, &j);
		if (quote_check == 1)
			return (1);
		else if (quote_check == 0)
			return (0);
	}
	if ((*s)[j + 1])
	{
		free(*s);
		*s = malloc(sizeof(char));
		*s[0] = '\0';
		return (1);
	}
	free(*var);
	return (0);
}

//	this function replaces in the str s the str_replace with the new_str
int	replace_var(char **s, char **str_replace, char *new_str, int *start)
{
	char	*suffix_pos;
	char	*substr_pos;
	int		rep_len;
	int		len_new_st;

	rep_len = ft_strlen(*str_replace);
	free(*str_replace);
	len_new_st = ft_strlen(new_str);
	if (alloc_string(s, ft_strlen(*s) - rep_len + len_new_st) == EXIT_FAILURE)
	{
		free(new_str);
		return (0);
	}
	substr_pos = *s + *start;
	if (substr_pos == NULL)
		return (0);
	suffix_pos = substr_pos + rep_len;
	ft_memmove(substr_pos + len_new_st, substr_pos + rep_len,
		ft_strlen(suffix_pos) + 1);
	ft_memcpy(substr_pos, new_str, len_new_st);
	free(new_str);
	*start += len_new_st - rep_len;
	return (1);
}

//	function to remove single or double quotes form the arg string
void	remove_quotes(char **args, int i, int j)
{
	if (args[i][j - 1])
	{
		if (args[i] && args[i][j - 1] == '\'')
			remove_char(args[i], '\'', j - 1, &j);
		else if (args[i] && args[i][j - 1] == '\"')
			remove_char(args[i], '\"', j - 1, &j);
	}
	j = 1;
	if (args[i] && args[i][0] == '\'')
		remove_char(args[i], '\'', 0, &j);
	else if (args[i] && args[i][0] == '\"')
		remove_char(args[i], '\"', 0, &j);
}

int	handle_exit_status(char *arg, int *j)
{
	if (arg[(*j) + 1] && arg[*j] == '$' && arg[(*j) + 1] == '?')
	{
		(*j)++;
		return (0);
	}
	else
		return (1);
}
//	function to convert the argument into the string
int	export_dollar_sign(char **args, t_env **env_lst)
{
	char	**env;
	char	*var;
	char	*replace;
	int		i;
	int		j;

	i = 0;
	j = 0;
	env = create_env_array(*env_lst);
	while (args[i])
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			if (quote_checker(args[i], j) && args[i][j] == '$'
				&& handle_exit_status(args[i], &j)
				&& search_for_var_in_env(&replace, env, args[i] + j, &var)
				&& !replace_var(&args[i], &var, replace, &j))
				return (free_two_dimensional_array(env), EXIT_FAILURE);
			j++;
		}
		remove_quotes(args, i, j);
		i++;
	}
	return (free_two_dimensional_array(env), EXIT_SUCCESS);
}
