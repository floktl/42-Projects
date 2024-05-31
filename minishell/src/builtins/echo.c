/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:45:53 by stopp             #+#    #+#             */
/*   Updated: 2024/05/31 21:24:15 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
	while (ft_strncmp(tree->args[i], "-n", 2) == 0)
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
