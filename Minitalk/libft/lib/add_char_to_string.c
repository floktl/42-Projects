/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char_to_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:08:34 by flo               #+#    #+#             */
/*   Updated: 2024/03/31 13:59:04 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//	function to add one character to the end of a string
int	add_char_to_string(char **string, char character)
{
	char	*add_str;
	char	*new_string;
	char	*old_string;

	add_str = (char *)ft_calloc(0, 2);
	if (!add_str)
		return (-1);
	add_str[0] = character;
	add_str[1] = '\0';
	old_string = *string;
	new_string = ft_strjoin(old_string, add_str);
	free(old_string);
	old_string = NULL;
	free(add_str);
	if (!new_string)
		return (-1);
	add_str = NULL;
	*string = new_string;
	return (0);
}
