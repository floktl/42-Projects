/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:45:53 by stopp             #+#    #+#             */
/*   Updated: 2024/06/10 18:53:36 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	n_checker(char *str)
{
	int	i;

	i = 2;
	if (ft_strncmp(str, "-n", 2) == 0)
	{
		i = 2;
		while (str[i])
		{
			if (str[i] != 'n')
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}

void	ft_echo(t_tree *tree)
{
	int	i;
	int	n_chk;

	i = 1;
	n_chk = 0;
	if (!tree->args[i])
	{
		ft_printf("\n");
		return ;
	}
	while (tree->args[i] && n_checker(tree->args[i]) == 0)
	{
		n_chk = 1;
		i++;
	}
	while (tree->args[i])
	{
		ft_printf("%s", tree->args[i]);
		if (tree->args[++i])
			ft_printf(" ");
	}
	if (!n_chk)
		ft_printf("\n");
	tree->exit_status = 0;
	return ;
}
