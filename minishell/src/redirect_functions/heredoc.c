/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:06:36 by stopp             #+#    #+#             */
/*   Updated: 2024/06/06 16:41:45 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	skip_here(int *i, char *str, char *here_doc)
{
	if (ft_strncmp(&str[*i], "<<", 2) == 0)
	{
		*i += 2;
		while (str[*i] == ' ')
			*i += 1;
		*i += ft_strlen(here_doc);
		return (1);
	}
	else
		return (0);
}

void	here_doc_loop(char	*str, int *fd)
{
	char	*buf;

	buf = NULL;
	signal(SIGINT, signal_handle);
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		buf = get_next_line(STDIN_FILENO);
		if (buf == NULL)
			break ;
		if (ft_strncmp(buf, str, ft_strlen(buf)) == 10)
			break ;
		write(fd[1], buf, ft_strlen(buf));
		free(buf);
	}
	if (buf)
		free(buf);
}

char	*create_heredoc(char **str, char *cmd_str, t_tree *tree)
{
	int		fd[2];
	int		pid;
	char	*new_cmdstr;

	if (pipe(fd) == -1)
		return (NULL);
	pid = fork();
	if (pid == -1)
		return (NULL);
	if (pid == 0)
	{
		here_doc_loop(*str, fd);
		exit (tree->exit_status);
	}
	waitpid(pid, &tree->exit_status, 0);
	if (WIFEXITED(tree->exit_status))
		tree->exit_status = WEXITSTATUS(tree->exit_status);
	close(fd[1]);
	tree->in_fd = fd[0];
	new_cmdstr = create_str(cmd_str, *str);
	free(*str);
	return (new_cmdstr);
}

char	*create_here_str(char *cmd_str, int i, int j)
{
	char	*here_str;

	here_str = malloc(sizeof(char) * (j + 1));
	if (!here_str)
		return (NULL);
	ft_strlcpy(here_str, &cmd_str[i], j + 1);
	return (here_str);
}

//	function to save the heredoc input in a string
char	*handle_heredoc(char *cmd_str, t_tree *tree)
{
	char	*here_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cmd_str[i])
	{
		if (ft_strncmp(&cmd_str[i], "<<", 2) == 0)
		{
			i += 2;
			while (cmd_str[i] && cmd_str[i] == ' ')
				i++;
			while (cmd_str[i + j]
				&& cmd_str[i + j] != '<' && cmd_str[i + j] != '>')
				j++;
			here_str = create_here_str(cmd_str, i, j);
			cmd_str = create_heredoc(&here_str, cmd_str, tree);
			i = 0;
		}
		if (cmd_str[i])
			i++;
	}
	return (cmd_str);
}
