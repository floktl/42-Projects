/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:50:39 by fkeitel           #+#    #+#             */
/*   Updated: 2024/02/29 09:56:14 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// this function limits the move of the map outside the visible window
int	range_check(t_window *window, int *x, int *y, int *z)
{
	//if (window.map_sz.xm_offset < -(((window.map_sz.xm_size - 2) * window.zoom_factor) / 2) - *x
	//	|| window.map_sz.ym_offset < -(((window.map_sz.ym_size - 2) * window.zoom_factor) / 2) - *y
	//	|| window.map_sz.xm_offset > (((window.map_sz.xm_size - 1) * window.zoom_factor) / 2) + WIDTH - *x
	//	|| window.map_sz.ym_offset > (((window.map_sz.ym_size - 1) * window.zoom_factor) / 2) + HEIGHT - *y)
	*window = *window;
	*x += 0;
	*y += 0;
	*z += 0;
	return (0);
}

// replace function for square root, why not, Math is fun!
// who needs the math.h library, definetly not me!
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

//this function calculates a missing z variable for a point p(x; y; z)
//input must be: A/cur(x; y; z) and B/next(x; y; z)
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

// Approximation of arctangent function
int	atan_approximation(int x)
{
	return (x - x * x * x / 3 + x * x * x * x * x / 5);
}

float	calc_angle(int a, int b, char which_side)
{
	double	tan_theta;
	double	theta_rad;
	float	theta_deg;

	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (b == 0)
		return (0.0f);
	tan_theta = (double)a / b;
	theta_rad = atan(tan_theta);
	theta_deg = theta_rad * (180.0 / 3.14159265358979323846f);
	if (which_side == 'Z')
	{
		theta_deg = 90 - theta_deg;
		if (theta_deg == 90)
			return (0.0f);
	}
	return (theta_deg);
}

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

int	round_to_int(float num)
{
	return ((num < 0) ? (int)(num - 0.5) : (int)(num + 0.5));
}

int	zoom_calc(t_window *window, t_coord *cur_point)
{
	if (window->zoom_factor != window->last_zoom_faktor && (window->zoom_factor > 0)
		&& window->zoom_factor < 100)
	{
		*cur_point = *cur_point;
		int dx = cur_point->xw - window->mouse_posx;
		int dy = cur_point->yw - window->mouse_posy;

		dx = abs(dx);
		dy = abs(dy);
		cur_point->len_cent *= (window->zoom_factor - window->last_zoom_faktor) + 1;
		cur_point->xw += dx * cur_point->len_cent * (window->zoom_factor - window->last_zoom_faktor + 1);
		cur_point->yw += dy * cur_point->len_cent * (window->zoom_factor - window->last_zoom_faktor + 1);
		cur_point->zw += cur_point->len_cent * (window->zoom_factor - window->last_zoom_faktor + 1);

		window->last_zoom_faktor = window->zoom_factor;
		return (1);
	}
	return (0);
}