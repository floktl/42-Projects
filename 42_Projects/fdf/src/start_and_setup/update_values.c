/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:24:45 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/13 10:46:00 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//------- this functions update the map values after changing parameters -------
//

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
	cur_point->xw = ft_round(cur_point->xm) + window->map_sz.xposmw;
	cur_point->yw = -ft_round(cur_point->ym) + window->map_sz.yposmw;
	return (0);
}

//	update the furthest points of the map from the map center
void	update_mapsize(t_sz *map_sz, t_coord *temp)
{
	if ((map_sz->maxsz_x_p) < temp->xw)
		map_sz->maxsz_x_p = temp->xw;
	if (map_sz->maxsz_x_m > temp->xw)
		map_sz->maxsz_x_m = temp->xw;
	if (map_sz->maxsz_y_p > temp->yw)
		map_sz->maxsz_y_p = temp->yw;
	if (map_sz->maxsz_y_m < temp->yw)
		map_sz->maxsz_y_m = temp->yw;
	map_sz->map_area = (map_sz->maxsz_x_p - map_sz->maxsz_x_m)
		* (map_sz->maxsz_y_m - map_sz->maxsz_y_p);
}
