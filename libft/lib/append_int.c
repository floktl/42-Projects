/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:05:44 by flo               #+#    #+#             */
/*   Updated: 2024/06/28 17:09:42 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * function to append a digit on an integer
 *
 * @param a the integer, which should be appended by b
 * @param b the integer to be append
 * @return the appended integer from a and b
 */
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
	while (n != 0)
	{
		digits++;
		n /= 10;
	}
	while (i++ < digits)
		multiplier *= 10;
	return (a * multiplier + b);
}
