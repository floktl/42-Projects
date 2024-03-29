/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:05:44 by flo               #+#    #+#             */
/*   Updated: 2024/03/27 14:17:31 by flo              ###   ########.fr       */
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
	while (n != 0)
	{
		digits++;
		n /= 10;
	}
	while (i++ < digits)
		multiplier *= 10;
	return (a * multiplier + b);
}
