/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:39:23 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/25 10:22:50 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_place(unsigned int n)
{
	if (n < 0)
		return (0);
	if (n < 10)
		return (1);
	if (n < 100)
		return (2);
	if (n < 1000)
		return (3);
	if (n < 10000)
		return (4);
	if (n < 100000)
		return (5);
	if (n < 1000000)
		return (6);
	if (n < 10000000)
		return (7);
	if (n < 100000000)
		return (8);
	if (n < 1000000000)
		return (9);
	return (10);
}

int	ft_putnbrui(int n, int fd, int counter)
{
	int				num_digits;
	int				i;
	unsigned int	num;
	char			digit_buffer[11];

	if (n < 0 && counter++ >= 0)
	{
		num = -n;
		if (ft_putchar('-', 1, 1) == -1)
			return (-1);
	}
	else
		num = n;
	num_digits = num_place(num);
	counter += num_digits;
	i = num_digits - 1;
	while (i >= 0)
	{
		digit_buffer[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	if (write(fd, digit_buffer, num_digits) == -1)
		return (-1);
	return (counter);
}
