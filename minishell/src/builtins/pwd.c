/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:32:06 by stopp             #+#    #+#             */
/*   Updated: 2024/05/31 19:05:54 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(t_tree *tree)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	write(STDOUT_FILENO, buf, ft_strlen(buf));
	write(1, "\n", 1);
	free(buf);
	tree->exit_status = 0;
	return ;
}
