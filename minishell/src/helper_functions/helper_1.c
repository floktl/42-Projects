/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:09:19 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/25 22:10:46 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	function to remove one character in the whole string from start until end
void	remove_char(char *str, char char_to_remove, int start, int end)
{
	char	*temp;
	int		old_len;
	int		new_len;

	old_len = start;
	new_len = start;
	if (!str)
		return ;
	while (str[old_len] != '\0' && old_len < end)
		if (str[old_len] != char_to_remove)
			str[new_len++] = str[old_len++];
	while (str[old_len] != '\0')
		str[new_len++] = str[old_len++];
	str[new_len] = '\0';
	if (new_len != old_len)
	{
		temp = malloc(sizeof(char) * new_len);
		if (!temp)
		{
			exit (1);
		}
		ft_strlcpy(temp, str, new_len);
		str = temp;
		free(temp);
	}
}
