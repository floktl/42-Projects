/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathmematics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:59:00 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/14 13:18:16 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"
#include <math.h>

//
//	mathematical functions, as i dont use the math.h library
//

// //	finds a point, when x is known, as well as the length to y and th degree
// void	find_new_point(double x1, double y1, double len_x_to_y, double deg)
// {
// 	double	angle_radians;
// 	double	x2;
// 	double	y2;

// 	angle_radians = radians(deg);
// 	x2 = x1 + len_x_to_y * cos(angle_radians);
// 	y2 = y1 + len_x_to_y * sin(angle_radians);
// 	printf("New point is at (%.2f, %.2f)\n", x2, y2);
// }

//	returns the absolute value of a float datatype
float	ft_fabs(float num)
{
	if (num > 0)
		return (num);
	else if (num < 0)
		return (num * -1);
	else
		return (0.0);
}

//	rounds a float number within a range given as parameter
float	round_float(float num, int range)
{
	float	factor;
	int		i;

	factor = 1.0;
	i = 0;
	while (i <= range)
	{
		factor *= 10.0;
		i++;
	}
	return ((float)((int)(num * factor + 0.5) / factor));
}

//	calculates an angle of an right triangle, when two sides are given
double	calc_angle(double x, double y)
{
	double	angle_rad;
	double	angle_deg;

	angle_rad = atan2(y, x);
	angle_deg = angle_rad * (180.0 / M_PI);
	if (angle_deg < 0)
		angle_deg += 360.0;
	return (angle_deg);
}

//	replace function for square root, why not, Math is fun!
//	Newton-Raphson Method
double	ft_sqrt(double a)
{
	double	x;
	double	epsilon;
	double	next;

	x = a;
	epsilon = 0.00000001;
	while (1)
	{
		next = 0.5 * (x + a / x);
		if ((next - x) * (next - x) < epsilon * epsilon)
			break ;
		x = next;
	}
	return (x);
}

//	this function calculates a missing z variable for a point p(x; y; z)
//	input must be: A/cur(x; y; z) and B/next(x; y; z)
float	calc_z(t_coord *point_a, t_coord *point_b, float x_p, float y_p)
{
	float	d_ap;
	float	d_ab;
	float	t;
	float	z_p;

	d_ap = ft_sqrt((x_p - point_a->xw) * (x_p - point_a->xw)
			+ (y_p - point_a->yw) * (y_p - point_a->yw));
	d_ab = ft_sqrt((point_b->xw - point_a->xw) * (point_b->xw
				- point_a->xw) + (point_b->yw - point_a->yw)
			* (point_b->yw - point_a->yw));
	if (d_ab == 0)
		return ((float)point_a->zw);
	t = d_ap / d_ab;
	z_p = point_a->zw + t * ((float)point_b->zw - (float)point_a->zw);
	z_p = (float)(z_p - point_a->zm) / (point_b->zw - point_a->zm);
	return (z_p);
}
