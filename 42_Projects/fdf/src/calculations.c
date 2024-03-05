/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:50:39 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/05 22:29:45 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// this function limits the move of the map outside the visible window
int	range_check(t_window *window, int x, int y, int z)
{
	if (x != 0)
	{
		if ((window->map_sz.xposmw + x - MARGIN) < -(window->map_sz.maxsz_x_p)
			|| (window->map_sz.xposmw - window->width + x + MARGIN)
			> -(window->map_sz.maxsz_x_m))
			return (0);
		else
			return (x);
	}
	if (y != 0)
	{
		if ((window->map_sz.yposmw - y - MARGIN) < -(window->map_sz.maxsz_y_p)
			|| (window->map_sz.yposmw - window->height - y + MARGIN)
			> -(window->map_sz.maxsz_y_m))
			return (0);
		else
			return (y);
	}
	else if (z != 0)
	{
		return (z);
	}
	return (0);
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

//	this function calculates the zoom in x and y direction of each coordinate,
//	depending on the mouse and/or map position
int	zoom_calc(t_window *window, t_coord *cur_point, double zoom)
{

	if (zoom != 0 && (window->zoom_factor > 3) && window->zoom_factor < 97)
	{

		double new_xm = cur_point->xm * zoom;
		double new_ym = cur_point->ym * zoom;
		cur_point->len_cent *= zoom;
		cur_point->xm = new_xm;
		cur_point->ym = new_ym;
		cur_point->xw = round(cur_point->xm) + round(window->map_sz.xm_offset) + window->cent_xw;
		cur_point->yw = -(round(cur_point->ym) + round(window->map_sz.ym_offset) - window->cent_yw);
		return (1);
	}
	return (0);
}

//if (window.map_sz.xm_offset < -(((window.map_sz.xm_size - 2)
		//* window.zoom_factor) / 2) - *x
//	|| window.map_sz.ym_offset < -(((window.map_sz.ym_size - 2)
		//* window.zoom_factor) / 2) - *y
//	|| window.map_sz.xm_offset > (((window.map_sz.xm_size - 1)
		//* window.zoom_factor) / 2) + WIDTH - *x
//	|| window.map_sz.ym_offset > (((window.map_sz.ym_size - 1)
		//* window.zoom_factor) / 2) + HEIGHT - *y)
