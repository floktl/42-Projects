/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirec_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:56:38 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/10 18:49:07 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	skip_rest(char *command_str, int s_quote, int d_quote, int i)
{
	if (s_quote)
	{
		while (command_str[i] && command_str[i] != '\'')
			i++;
		if (command_str[i] && command_str[i] != '\'')
			return (EXIT_FAILURE);
		while (command_str[i] && command_str[i] != ' ')
			i++;
	}
	if (d_quote)
	{
		while (command_str[i] && command_str[i] != '\"')
			i++;
		if (command_str[i] && command_str[i] != '\"')
			return (EXIT_FAILURE);
		while (command_str[i] && command_str[i] != ' ')
			i++;
	}
	return (EXIT_SUCCESS);
}

int	check_cat(char *str)
{
	int	i;

	if (ft_strncmp(str, "cat", 3) == 0)
		i = 3;
	else
		i = 4;
	while (str[i])
	{
		if (str[i] != ' ' || str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

char	**cpy_args(char **new, char ***args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*args)[i])
	{
		if ((*args)[i][0] != '\0')
		{
			new[j] = ft_strdup((*args)[i]);
			if (!new[j])
			{
				free_two_dimensional_array(new);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	new[j] = NULL;
	free_two_dimensional_array(*args);
	return (new);
}

int	update_args(char ***args)
{
	char	**new;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while ((*args)[i])
	{
		if ((*args)[i][0] != '\0')
			count++;
		i++;
	}
	new = malloc(sizeof(char *) * (count + 1));
	if (!new)
		return (-1);
	new[count] = NULL;
	new = cpy_args(new, args);
	*args = new;
	return (-1);
}
