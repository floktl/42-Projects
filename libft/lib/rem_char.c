/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:12:42 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 19:38:45 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * 	function to remove one charcter from a string at a position
 *
 * @param str string
 * @param pos position of the character to remove
 */
void	rem_char(char *str, int pos)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = pos;
	while (i < len)
	{
		str[i] = str[i + 1];
		i++;
	}
}
