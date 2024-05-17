/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:09:19 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/15 17:03:53 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	function to remove one character in the whole string from start until end
void	remove_char(char *str, char char_to_remove, int old_len, int *end)
{
	char	*temp;
	int		new_len;

	new_len = old_len;
	if (!str)
		return ;
	while (str[old_len] != '\0' && old_len < *end)
	{
		if (str[old_len] != char_to_remove)
			str[new_len++] = str[old_len];
		old_len++;
	}
	while (str[old_len] != '\0')
		str[new_len++] = str[old_len++];
	str[new_len] = '\0';
	if (new_len != old_len)
	{
		temp = malloc(sizeof(char) * new_len);
		if (!temp)
			exit (1);
		*end = new_len;
		ft_strlcpy(temp, str, new_len);
		str = temp;
		free(temp);
	}
}

//	lst add back function modified for the tree struct
void	ft_treeadd_back(t_tree **lst, t_tree *new, t_tree **parent)
{
	t_tree	*current;

	new->parent_pipe = *parent;
	*parent = new;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->child_pipe != NULL)
		current = current->child_pipe;
	current->child_pipe = new;
}

//	this function allocates the new substring for the string replace in a string
int	alloc_string(char **s, int result_len)
{
	char	*temp;
	int		str_len;

	temp = NULL;
	str_len = (int)ft_strlen(*s);
	if (result_len != str_len)
	{
		temp = (char *)malloc(sizeof(char) * (result_len + 1));
		if (!temp)
			return (EXIT_FAILURE);
		ft_memcpy(temp, *s, str_len);
		temp[str_len] = '\0';
		free(*s);
		*s = temp;
	}
	return (EXIT_SUCCESS);
}

//	function to check if string is in single or double quotes
int	quote_checker(char *arg, int j)
{
	static int	single_quote = 0;
	static int	double_quote = 0;

	if (j == 0)
	{
		single_quote = 0;
		double_quote = 0;
	}
	if (arg[j] && arg[j] == '\'' && !(double_quote))
	{
		single_quote = !(single_quote);
	}
	else if (arg[j] && arg[j] == '\"' && !(single_quote))
	{
		double_quote = !(double_quote);
	}
	if (single_quote)
		return (0);
	return (1);
}
