/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:02:49 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/07 16:53:07 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//	this function calculates the zoom in x and y direction of each coordinate,
//	depending on the mouse and/or map position
int	zoom_calc(t_window *window, t_coord *cur_point, double zoom)
{
	double	new_xm;
	double	new_ym;
	double	original_xm;
	double	original_ym;

	if (zoom == 0)
		return (0);
	new_xm = cur_point->xm * zoom;
	new_ym = cur_point->ym * zoom;
	original_xm = cur_point->xm;
	original_ym = cur_point->ym;
	cur_point->len_cent *= zoom;
	cur_point->xm = new_xm;
	cur_point->ym = new_ym;
	cur_point->xw = round(original_xm + window->map_sz.xm_offset)
		+ window->cent_xw;
	cur_point->yw = -round(original_ym + window->map_sz.ym_offset)
		+ window->cent_yw;
	return (0);
}

//	calculate the zoom based on the mouse position
void	calculate_zoom_pos(t_window *window, double zoom)
{
	double		dx;
	double		dy;

	mlx_get_mouse_pos(window->mlx, &window->map_sz.xposmw, &window->mouse_posy);
	if (zoom == 0)
		return ;
	dx = check_zoom_direction(window->map_sz.xposmw - window->mouse_posx);
	dy = check_zoom_direction(window->mouse_posy - window->map_sz.yposmw);
	window->mouse_posx = window->cent_xw;
	window->mouse_posy = window->cent_yw;
	if (zoom == 0.9)
	{
		if (dx == 1.1)
			dx = 0.9;
		else if (dx == 0.9)
			dx = 1.1;
		if (dy == 1.1)
			dy = 0.9;
		else if (dy == 0.9)
			dy = 1.1;
	}
	window->map_sz.xm_offset *= dx;
	window->map_sz.ym_offset *= dy;
	window->map_sz.xposmw = window->cent_xw + round(window->map_sz.xm_offset);
	window->map_sz.yposmw = window->cent_yw - round(window->map_sz.ym_offset);
}

//	function to check, if there is a change in the zoom faktor
double	check_if_zoomed(t_window *window, int x_set, int y_set, double zoom)
{
	window->mouse_posx = window->width / 2;
	window->mouse_posy = window->height / 2;
	if (zoom == 0)
	{
		window->map_sz.xm_offset += x_set;
		window->map_sz.ym_offset += y_set;
		window->map_sz.xposmw += x_set;
		window->map_sz.yposmw -= y_set;
	}
	else
		calculate_zoom_pos(window, zoom);
	return (zoom);
}
