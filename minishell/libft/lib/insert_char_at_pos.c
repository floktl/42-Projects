/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_char_at_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:53:27 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/06 13:07:13 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

//	function to insert a character at a defined position in a string
//	returns the new string with the added character
char	*insert_char_at_position(char *s, char c, size_t len, size_t pos)
{
	char	*new_s;

	new_s = malloc((len + 2) * sizeof(char));
	if (new_s == NULL)
	{
		ft_printf("malloc");
		return (NULL);
	}
	ft_strlcpy(new_s, s, pos);
	new_s[pos] = c;
	strcpy(new_s + pos + 1, s + pos);
	return (new_s);
}
