/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_to_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:39:06 by flo               #+#    #+#             */
/*   Updated: 2024/03/27 14:17:37 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//function to convert an array with 8 bits to a character
char	bits_to_char(const int bits[8])
{
	char	result;
	int		i;

	result = 0;
	i = 0;
	while (i < 8)
	{
		result |= bits[i] << i;
		i++;
	}
	return (result);
}
