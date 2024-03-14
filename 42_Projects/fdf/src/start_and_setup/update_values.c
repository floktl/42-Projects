/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:24:45 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/14 16:57:54 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"
#include <math.h>

//
//------- this functions update the map values after changing parameters -------
//
void	rotate(double *a, double *b, double angle, char axis)
{
	double	rad;
	double	cos_a;
	double	sin_a;
	double	new_a;
	double	new_b;

	rad = angle * (PI / 180.0);
	cos_a = cos(rad);
	sin_a = sin(rad);
	if (axis == 'X')
	{
		new_a = (*a) * cos_a - (*b) * sin_a;
		new_b = (*a) * sin_a + (*b) * cos_a;

	}
	if (axis == 'Y')
	{
		new_a = (*b) * cos_a - (*a) * sin_a;
		new_b = (*a) * cos_a + (*b) * sin_a;
	}
	if (axis == 'Z')
	{
		new_a = (*a) * cos_a - (*b) * sin_a;
		new_b = (*a) * sin_a + (*b) * cos_a;
	}
	*a = new_a;
	*b = new_b;
}

int	rotation_calc(t_window *window, t_coord *cur_point)
{
	double	temp_xm;
	double	temp_ym;
	double	temp_zm;

	temp_xm = cur_point->xm;
	temp_ym = cur_point->ym;
	temp_zm = cur_point->zm;
	rotate(&temp_ym, &temp_zm, window->map_sz.xm_rot_deg, 'X');
	rotate(&temp_zm, &temp_xm, window->map_sz.ym_rot_deg, 'Y');
	rotate(&temp_xm, &temp_ym, window->map_sz.zm_rot_deg, 'Z');
	cur_point->xw = ft_round(temp_xm) + window->map_sz.xposmw;
	cur_point->yw = window->map_sz.yposmw - ft_round(temp_ym);
	cur_point->zw = ft_round(temp_zm) + window->map_sz.zm_offset;
	return (0);
}

//this function updates all important variables to each point in map
int32_t	update_coord(t_window *window, int x_shift, int y_shift)
{
	t_coord		*temp;
	t_sz		*map_sz;

	temp = window->coord;
	map_sz = &window->map_sz;
	map_sz->xm_offset += x_shift;
	map_sz->ym_offset += y_shift;
	map_sz->xposmw += x_shift;
	map_sz->yposmw += y_shift;
	calculate_zoom_pos(window);
	map_sz->maxsz_x_p = window->map_sz.xposmw;
	map_sz->maxsz_x_m = window->map_sz.xposmw;
	map_sz->maxsz_y_p = window->map_sz.yposmw;
	map_sz->maxsz_y_m = window->map_sz.yposmw;
	while (temp != NULL)
	{
		temp->xw += x_shift;
		temp->yw += y_shift;
		zoom_calc(window, temp);
		rotation_calc(window, temp);
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
