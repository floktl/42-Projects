/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathematics2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:00:17 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/14 12:26:07 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//--------------------- using math.h would be way easier ----------------------
//

//	Approximation of arctangent function
int	ft_atan(int x)
{
	return (x - x * x * x / 3 + x * x * x * x * x / 5);
}

//	returns the radiant
double	radians(double degrees)
{
	return (degrees * 3.14159265358979323846 / 180.0);
}

//	rounds a double or float datatype to an integer
int	ft_round(double num)
{
	if (num < 0)
		return ((int)(num - 0.5));
	else
		return ((int)(num + 0.5));
}

//	returns always a positive number, no matter if num is + or -
int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

void	degree(int *rot)
{
	if (*rot >= 360)
		*rot -= 360;
	if (*rot < 0)
		*rot += 360;
}

//Point rotateY(Point p, double theta)
//{
//	Point pRotated;
//	double rad = theta * M_PI / 180.0; // Convert degrees to radians
//	pRotated.x = cos(rad) * p.x + sin(rad) * p.z;
//	pRotated.y = p.y; // Y-coordinate remains unchanged
//	pRotated.z = -sin(rad) * p.x + cos(rad) * p.z;
//	return (pRotated);
//}
