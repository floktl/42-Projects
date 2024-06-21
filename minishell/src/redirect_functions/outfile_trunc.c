/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outfile_trunc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:56:51 by stopp             #+#    #+#             */
/*   Updated: 2024/06/06 15:17:16 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*update_cmdstr_trunc(char *cmdstr, int skip_len)
{
	int		i;
	int		j;
	int		del;
	char	*new_cmdstr;

	i = 0;
	j = 0;
	del = 0;
	new_cmdstr = malloc(ft_strlen(cmdstr) - j + 1);
	if (!new_cmdstr)
		return (NULL);
	new_cmdstr[ft_strlen(cmdstr) - j] = '\0';
	while (cmdstr[j])
	{
		if (ft_strncmp(&cmdstr[j], ">", 1) == 0 && del == 0)
		{
			j += skip_len;
			new_cmdstr[i] = cmdstr[j];
			del = 1;
		}
		else
			new_cmdstr[i++] = cmdstr[j++];
	}
	free(cmdstr);
	return (new_cmdstr);
}

char	*open_outfile_trunc(t_tree *tree, char *cmdstr, char *outfile)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (validate_outfile(outfile, tree) == 0)
		return (free(outfile), free(cmdstr), empty_str());
	tree->out_fd = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (!tree->out_fd)
		return (NULL);
	while (cmdstr[i])
	{
		if (ft_strncmp(&cmdstr[i], ">", 1) == 0)
		{
			j = 1;
			while (cmdstr[i + j] && cmdstr[i + j] == ' ')
				j++;
			j += ft_strlen(outfile);
			break ;
		}
		i++;
	}
	cmdstr = update_cmdstr_trunc(cmdstr, j);
	free(outfile);
	return (cmdstr);
}

char	*handle_trunc(char *cmdstr, t_tree *tree)
{
	int		i;
	int		j;
	char	*outfile;

	i = -1;
	j = 0;
	while (cmdstr[++i])
	{
		if (ft_strncmp(&cmdstr[i], ">", 1) == 0)
		{
			i += 1;
			while (cmdstr[i] && cmdstr[i] == ' ')
				i++;
			while (cmdstr[i + j]
				&& cmdstr[i + j] != '<' && cmdstr[i + j] != '>')
				j++;
			outfile = malloc(sizeof(char) * (j + 1));
			if (!outfile)
				return (NULL);
			ft_strlcpy(outfile, &cmdstr[i], j + 1);
			cmdstr = open_outfile_trunc(tree, cmdstr, outfile);
			break ;
		}
	}
	return (cmdstr);
}
