/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:33:56 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/17 11:33:32 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	public libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <termios.h>
#include <readline/readline.h>
#include <readline/history.h>

int	init_data(int argc, char *argv[], t_pipex *data, char **envp)
{
	data->cmd = NULL;
	if (ft_strncmp(argv[1], ">>", 2) == 0)
	{
		data->here_doc = 1;
		if (!here_doc(argv))
			return (0);
		data->cmd_count = argc - 4;
	}
}

static int	here_doc(char *argv[])
{
	char	*buf;
	int		fd[2];

	if (pipe(fd) == -1)
		return (0);
	while (1)
	{
		buf = get_next_line(STDIN_FILENO);
		if (ft_strncmp(buf, argv[2], ft_strlen(buf)) == 10)
			break ;
		write(fd[1], buf, ft_strlen(buf));
		free(buf);
	}
	free(buf);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	return (1);
}
