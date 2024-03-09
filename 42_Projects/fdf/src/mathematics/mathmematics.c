/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathmematics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:59:00 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/09 19:49:06 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

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
double	calc_angle(double a, double b, char which_side)
{
	double	tan_theta;
	double	theta_rad;
	double	theta_deg;

	if (b == 0 || a == 0)
		return (0.0f);
	if (a < 0)
		a *= -1.0f;
	if (b < 0)
		b *= -1.0f;
	tan_theta = (a / b);
	theta_rad = ft_atan(tan_theta);
	theta_deg = theta_rad * (180.0 / 3.14159265358979323846f);
	if (which_side == 'Z')
	{
		theta_deg = 90 - theta_deg;
		if (ft_fabs(theta_deg - 90) < 1e-6)
			return (0.0f);
	}
	return (theta_deg);
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
float	calc_z(t_coord *cur, t_coord *next, float x_p, float y_p)
{
	float	d_ap;
	float	d_ab;
	float	t;
	float	z_p;

	d_ap = ft_sqrt((x_p - cur->xw) * (x_p - cur->xw)
			+ (y_p - cur->yw) * (y_p - cur->yw));
	d_ab = ft_sqrt((next->xw - cur->xw) * (next->xw
				- cur->xw) + (next->yw - cur->yw)
			* (next->yw - cur->yw));
	if (d_ab == 0)
		return ((float)cur->zw);
	t = d_ap / d_ab;
	z_p = cur->zw + t * ((float)next->zw - (float)cur->zw);
	return (z_p);
}

