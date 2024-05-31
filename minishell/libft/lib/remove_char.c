/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:20:25 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/19 11:12:09 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
			return ;
		*end = new_len;
		ft_strlcpy(temp, str, new_len);
		str = temp;
		free(temp);
	}
}
