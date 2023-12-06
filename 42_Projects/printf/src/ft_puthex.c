/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:47:11 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/24 09:42:12 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long *hexadecimal, int upper_lower, int counter)
{
	char			*hex_chars;
	char			address_str[17];
	int				i;
	unsigned int	index;

	if (upper_lower == 'x')
		hex_chars = "0123456789abcdef";
	else if (upper_lower == 'X')
		hex_chars = "0123456789ABCDEF";
	if (*hexadecimal == 0)
		return (ft_printstr("0", 0));
	i = sizeof(unsigned long) * 2 - 1 ;
	index = 0;
	while (i >= 0)
	{
		if (((hex_chars[(*hexadecimal >> (i * 4)) & 0xF]) != '0' \
			|| index > 0 || i == 0) && counter++ >= 0)
			address_str[index++] = hex_chars[(*hexadecimal >> (i * 4)) & 0xF];
		i--;
	}
	address_str[index] = '\0';
	counter = ft_printstr(address_str, 0);
	return (counter);
}
