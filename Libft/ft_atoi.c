/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:00:23 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/08 20:12:33 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int store;
	int sign;
	size_t counter;
	int bigger_ten;

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
			return store;
		store = store * 10 + bigger_ten;
		counter++;
	}
	return store * sign;
}

int main() {
    const char* str = "123446666"; // Replace with the string you want to convert
    int result = ft_atoi(str);

    printf("Original string: %s\n", str);
    printf("Converted integer: %d\n", result);

    return 0;
}
