/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:24:45 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/09 08:55:15 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//this function updates all important variables to each point in map
int32_t	update_coord(t_window *window, int x_set, int y_set)
{
	t_coord		*temp;
	t_sz		*map_sz;

	temp = window->coord;
	map_sz = &window->map_sz;
	map_sz->xm_offset += x_set;
	map_sz->ym_offset += y_set;
	map_sz->xposmw += x_set;
	map_sz->yposmw += y_set;
	calculate_zoom_pos(window);
	map_sz->maxsz_x_p = window->map_sz.xposmw;
	map_sz->maxsz_x_m = window->map_sz.xposmw;
	map_sz->maxsz_y_p = window->map_sz.yposmw;
	map_sz->maxsz_y_m = window->map_sz.yposmw;
	while (temp != NULL)
	{
		temp->xw += x_set;
		temp->yw += y_set;
		zoom_calc(window, temp);
		update_mapsize(&window->map_sz, temp);
		temp = temp->next;
	}
	window->zoom = ZOOM_DEFAULT;
	print_stacks(window);
	return (EXIT_SUCCESS);
}

//	this function calculates the zoom in x and y direction of each coordinate,
//	depending on the mouse and/or map position
int	zoom_calc(t_window *window, t_coord *cur_point)
{
	if (window->zoom == ZOOM_DEFAULT)
		return (0);
	cur_point->len_cent *= window->zoom;
	cur_point->xm *= window->zoom;
	cur_point->ym *= window->zoom;
	cur_point->xw = round(cur_point->xm) + window->map_sz.xposmw;
	cur_point->yw = -round(cur_point->ym) + window->map_sz.yposmw;
	return (0);
}
