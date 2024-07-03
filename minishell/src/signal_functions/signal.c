/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:47:36 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/21 14:52:13 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	exit the process or prints quit
void	signal_handle(int signo)
{
	(void)signo;
	if (signo == SIGQUIT)
	{
		ft_printf("QUIT: 3\n");
		exit(131);
	}
	if (signo == SIGINT)
		exit(130);
}

//	^C clears current input line, redraws prompt, and moves cursor to a new line
void	signal_handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	//rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
	return ;
}
