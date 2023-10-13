/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:33:22 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/13 10:39:05 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	num_places(int n)
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

int	check_negativ(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	char	*c;
	int		is_negativ;
	int		num_digits;
	int		i;

	c = NULL;
	is_negativ = check_negativ(n);
	if (is_negativ == 1)
		n = n * (-1);
	num_digits = num_places(n) + is_negativ;
	c = (char *)malloc(num_digits + 1);
	if (c == NULL)
		return (NULL);
	if (is_negativ == 1)
		c[0] = '-';
	i = num_digits - 1;
	while (i >= is_negativ)
	{
		c[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	c[num_digits + is_negativ] = '\0';
	return (c);
}

/*int main(void)
{
    int n = 18376789;
    char *s;

    s = ft_itoa(n);
    printf("%s", s);
    free(s);
    return 0;
}*/
