/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:24:45 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/08 22:55:50 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//this function updates all important variables to each point in map
int32_t	update_coord(t_window *window, int x_set, int y_set, double zoom)
{
	t_coord		*temp;
	t_sz		*map_sz;

	temp = window->coord;
	map_sz = &window->map_sz;
	map_sz->xm_offset += x_set;
	map_sz->ym_offset += y_set;
	map_sz->xposmw += x_set;
	map_sz->yposmw += y_set;
	calculate_zoom_pos(window, &zoom);
	map_sz->maxsz_x_p = window->map_sz.xposmw;
	map_sz->maxsz_x_m = window->map_sz.xposmw;
	map_sz->maxsz_y_p = window->map_sz.yposmw;
	map_sz->maxsz_y_m = window->map_sz.yposmw;
	while (temp != NULL)
	{
		temp->xw += x_set;
		temp->yw += y_set;
		update_mapsize(&window->map_sz, temp);
		zoom_calc(window, temp, zoom);
		temp = temp->next;
	}
	print_stacks(window);
	return (EXIT_SUCCESS);
}

//	this function calculates the zoom in x and y direction of each coordinate,
//	depending on the mouse and/or map position
int	zoom_calc(t_window *window, t_coord *cur_point, double zoom)
{
	if (zoom == ZOOM_DEFAULT)
		return (0);
	cur_point->len_cent *= zoom;
	cur_point->xm *= zoom;
	cur_point->ym *= zoom;
	cur_point->xw = round(cur_point->xm) + window->map_sz.xposmw;
	cur_point->yw = -round(cur_point->ym) + window->map_sz.yposmw;
	return (0);
}
