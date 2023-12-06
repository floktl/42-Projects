/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkcases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:48:07 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/25 10:22:19 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_p(va_list argument)
{
	int		check;
	size_t	*ptr;
	int		counter;

	counter = 0;
	ptr = va_arg(argument, void *);
	check = ft_printstr("0x", 0);
	if (check == -1)
		return (-1);
	counter += check;
	check = ft_puthex((unsigned long *)&ptr, 'x', 0);
	if (check == -1)
		return (-1);
	counter += check;
	return (counter);
}

int	ft_checkcases(const char format, va_list argument, int counter)
{
	unsigned long	value;

	if (format == 'c')
		counter = ft_putchar(va_arg(argument, int), 1, 1);
	else if (format == 'd' || format == 'i')
		counter = ft_putnbrui(va_arg(argument, int), 1, 0);
	else if (format == 's')
		counter = ft_printstr(va_arg(argument, char *), 0);
	else if (format == 'p')
		counter = check_p(argument);
	else if (format == 'x' || format == 'X')
	{
		value = va_arg(argument, unsigned int);
		counter = ft_puthex(&value, format, 0);
	}
	else if (format == 'u')
		counter = ft_putunbr(va_arg(argument, unsigned int), 1);
	else if (format == '%' && counter++ >= 0)
		counter = ft_putchar('%', 1, 1);
	return (counter);
}
