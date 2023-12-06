/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:45:56 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/25 10:22:45 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n, int fd)
{
	int	counter;
	int	check;
	int	check2;

	counter = 0;
	if (n >= 10)
	{
		check2 = ft_putunbr(n / 10, fd);
		if (check2 == -1)
			return (-1);
		counter += check2;
	}
	check = ft_putchar((n % 10 + '0'), fd, 1);
	if (check == -1)
		return (-1);
	counter++;
	return (counter);
}
