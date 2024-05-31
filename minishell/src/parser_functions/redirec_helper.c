/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirec_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:56:38 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/31 21:57:03 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**cpy_args(char **new, char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		if (args[i][0] != '\0')
		{
			new[j] = ft_strdup(args[i]);
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
	free_two_dimensional_array(args);
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
		return (0);
	new[count] = NULL;
	new = cpy_args(new, *args);
	*args = new;
	return (0);
}
