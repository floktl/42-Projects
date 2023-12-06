/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:27:14 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/24 11:26:25 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		counter;
	int		n;
	va_list	arguments;
	int		checkerror;

	counter = 0;
	n = 0;
	va_start (arguments, format);
	while (format[counter] != '\0')
	{
		if (format[counter] == '%')
		{
			checkerror = ft_checkcases(format[counter++ + 1], arguments, 0);
			n = n + checkerror;
		}
		else if (n++ >= 0)
			checkerror = ft_putchar(format[counter], 1, 1);
		if (checkerror == -1)
			return (-1);
		counter++;
	}
	va_end(arguments);
	return (n);
}
