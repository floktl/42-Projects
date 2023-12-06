/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:48:48 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/24 11:06:21 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str, int counter)
{
	int	check;

	if (!str)
	{
		check = ft_printstr("(null)", 0);
		if (check == -1)
			return (-1);
		return (6);
	}
	while (str[counter])
	{
		if (ft_putchar(str[counter], 1, 1) == -1)
			return (-1);
		counter++;
	}
	return (counter);
}
