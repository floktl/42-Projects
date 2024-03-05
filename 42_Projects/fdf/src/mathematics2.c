/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathematics2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:00:17 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/01 17:31:06 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Approximation of arctangent function
int	atan_approximation(int x)
{
	return (x - x * x * x / 3 + x * x * x * x * x / 5);
}

// returns the radiant
double	radians(double degrees)
{
	return (degrees * 3.14159265358979323846 / 180.0);
}

//int	round_to_int(float num)
//{
//	return ((num < 0) ? (int)(num - 0.5) : (int)(num + 0.5));
//}