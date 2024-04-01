/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:05:44 by flo               #+#    #+#             */
/*   Updated: 2024/03/31 14:25:45 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//function to append a digit on an integer
int	append_int(int a, int b)
{
	int	multiplier;
	int	digits;
	int	i;
	int	n;

	n = b;
	i = 0;
	multiplier = 1;
	digits = 0;
	if (b == 0 && a != 0)
	{
		return (a * 10);
	}
	while (n != 0)
	{
		digits++;
		n /= 10;
	}
	while (i++ < digits)
		multiplier *= 10;
	return (a * multiplier + b);
}

//int main()
//{
//	printf("%d", append_int(1, 0));
//	return (0);
//}