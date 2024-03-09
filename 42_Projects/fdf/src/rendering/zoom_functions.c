/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:02:49 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/09 20:12:46 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//-------------- functions to calculate the changes when zooming --------------
//

//	this functions calculates the zoom direction of the map center depending
//	on the mous position
int	check_mouse_position(t_window *window, double *zoom_x, double *zoom_y)
{
	double	zoom_direction_x;
	double	zoom_direction_y;

	if (!window)
		return (-1);
	zoom_direction_x = check_zoom_direction(window->map_sz.xposmw,
			window->mouse_posx, window->zoom);
	zoom_direction_y = check_zoom_direction(window->map_sz.yposmw,
			window->mouse_posy, window->zoom);
	*zoom_x = -ft_abs(window->map_sz.xposmw - window->mouse_posx)
		* (ZOOM_DEFAULT - zoom_direction_x);
	*zoom_y = -ft_abs(window->map_sz.yposmw - window->mouse_posy)
		* (ZOOM_DEFAULT - zoom_direction_y);
	return (0);
}

//	calculate the zoom based on the mouse position
void	calculate_zoom_pos(t_window *window)
{
	double	zoom_x;
	double	zoom_y;

	if (window->zoom == ZOOM_DEFAULT)
		return ;
	check_mouse_position(window, &zoom_x, &zoom_y);
	if (((window->map_sz.maxsz_x_p + zoom_x) < MARGIN)
		|| ((window->map_sz.maxsz_x_m + zoom_x) > (window->width - MARGIN))
		|| ((window->map_sz.maxsz_y_m + zoom_y) < MARGIN)
		|| ((window->map_sz.maxsz_y_p + zoom_y)
			> (window->height - MARGIN)))
	{
		zoom_x = 0;
		zoom_y = 0;
	}
	window->map_sz.xposmw += zoom_x;
	window->map_sz.yposmw += zoom_y;
	window->map_sz.xm_offset = -window->cent_xw + window->map_sz.xposmw;
	window->map_sz.ym_offset = -window->cent_yw + window->map_sz.yposmw;
}

//	this functions calclulates the zoom with the scroll wheel or trackpad
void	ft_scroll(double xoffset, double yoffset, void *param)
{
	t_window	*window;

	window = (t_window *)param;
	if (window->zoom != ZOOM_DEFAULT && xoffset)
		return ;
	if (yoffset < 0)
	{
		if (window->map_sz.map_area * ZOOM_P < window->max_zoom_size)
			window->zoom = ZOOM_P;
	}
	else if (yoffset > 0)
	{
		if (window->map_sz.map_area * ZOOM_M > window->min_zoom_size)
			window->zoom = ZOOM_M;
	}
}
