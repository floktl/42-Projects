/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:02:49 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/09 14:17:35 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	positive(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

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
	*zoom_x = -positive(window->map_sz.xposmw - window->mouse_posx)
		* (ZOOM_DEFAULT - zoom_direction_x);
	*zoom_y = -positive(window->map_sz.yposmw - window->mouse_posy)
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
		zoom_x *= 0;
		zoom_y *= 0;
	}
	window->map_sz.xposmw += zoom_x;
	window->map_sz.yposmw += zoom_y;
	window->map_sz.xm_offset = -window->cent_xw + window->map_sz.xposmw;
	window->map_sz.ym_offset = -window->cent_yw + window->map_sz.yposmw;
}

void	ft_scroll(double xoffset, double yoffset, void *param)
{
	t_window	*window;

	window = (t_window *)param;
	if (window->zoom != ZOOM_DEFAULT)
		return ;
	xoffset = 0;
	window->map_sz.map_area = (window->map_sz.maxsz_x_p
			- window->map_sz.maxsz_x_m)
		* (window->map_sz.maxsz_y_m - window->map_sz.maxsz_y_p);
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
