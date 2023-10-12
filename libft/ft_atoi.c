/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:00:23 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/11 21:59:55 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	store;
	int	sign;
	int	counter;
	int	bigger_ten;

	store = 0;
	sign = 1;
	counter = 0;
	bigger_ten = 0;
	if (str[0] == '-')
	{
		sign = -1;
		counter++;
	}
	if (str[0] == '+')
		counter++;
	while (str[counter])
	{
		bigger_ten = ((int)str[counter] - '0');
		if (bigger_ten < 0 || bigger_ten > 9)
			return (store);
		store = store * 10 + bigger_ten;
		counter++;
	}
	return (store * sign);
}
