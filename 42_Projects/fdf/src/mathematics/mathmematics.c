/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathmematics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:59:00 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/06 16:59:07 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//	mathematical functions, as i dont use the math.h library
//

//	finds a point, when x is known, as well as the length to y and th degree
void	find_new_point(double x1, double y1, double len_x_to_y, double deg)
{
	double	angle_radians;
	double	x2;
	double	y2;

	angle_radians = radians(deg);
	x2 = x1 + len_x_to_y * cos(angle_radians);
	y2 = y1 + len_x_to_y * sin(angle_radians);
	printf("New point is at (%.2f, %.2f)\n", x2, y2);
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
	theta_rad = atan(tan_theta);
	theta_deg = theta_rad * (180.0 / 3.14159265358979323846f);
	if (which_side == 'Z')
	{
		theta_deg = 90 - theta_deg;
		if (fabs(theta_deg - 90) < 1e-6)
			return (0.0f);
	}
	return (theta_deg);
}

// replace function for square root, why not, Math is fun!
// Newton-Raphson Method
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
