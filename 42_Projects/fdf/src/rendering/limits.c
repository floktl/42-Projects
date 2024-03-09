/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:50:39 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/09 19:53:54 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//------------------ this functions limits the movemoent of the map------------
//

//	this function limits the move of the map outside the visible window
//	Margin is the borderlimit, maxsz are the furthest 4 points seen from
//	the center of the map
int	range_check(t_window *window, int x, int y, int z)
{
	*window = *window;
	if (x != 0)
	{
		if (((window->map_sz.maxsz_x_p + x) < MARGIN)
			|| ((window->map_sz.maxsz_x_m + x) > (window->width - MARGIN)))
			return (0);
		else
			return (x);
	}
	if (y != 0)
	{
		if (((window->map_sz.maxsz_y_m + y) < MARGIN)
			|| ((window->map_sz.maxsz_y_p + y) > (window->height - MARGIN)))
			return (0);
		else
			return (y);
	}
	else if (z != 0)
		return (z);
	return (0);
}

//	this function checks if the mouse is outside the MARGIN (window boarder)
int	check_margin_border(t_window *window)
{
	if (window->mouse_posx < 0 || window->mouse_posx > window->width
		|| window->mouse_posy < 0 || window->mouse_posy > window->height)
	{
		window->mouse_posx = window->cent_xw;
		window->mouse_posy = window->cent_xw;
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
