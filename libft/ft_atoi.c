/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:00:23 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/13 12:57:35 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	count;
	int	bigger_ten;

	count = 0;
	bigger_ten = 0;
	while (str[count] == '\t' || str[count] == '\n' || str[count] == '\v'
		|| str[count] == '\f' || str[count] == '\r' || str[count] == ' ')
		count++;
	sign = (str[count] == '-') ? -1 : 1;
	if (str[count] == '+')
		count++;
	while (str[count])
	{
		bigger_ten = ((int)str[count] - '0');
		if (bigger_ten < 0 || bigger_ten > 9)
			return (sign);
		sign = sign * 10 + bigger_ten;
		count++;
	}
	return (sign * sign);
}
