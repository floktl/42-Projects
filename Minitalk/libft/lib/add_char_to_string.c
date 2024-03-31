/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char_to_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:08:34 by flo               #+#    #+#             */
/*   Updated: 2024/03/30 20:10:16 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//	function to add one character to the end of a string
int	add_char_to_string(char **string, char character)
{
	char	*add_str;
	char	*new_string;
	char	*old_string;

	add_str = malloc(sizeof(char) * 2);
	if (!add_str)
		return (-1);
	add_str[0] = character;
	add_str[1] = '\0';
	old_string = *string;
	new_string = ft_strjoin(old_string, add_str);
	free(old_string);
	free(add_str);
	if (!new_string)
		return (-1);
	*string = new_string;
	return (0);
}
