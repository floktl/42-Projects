/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:02:49 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/08 23:13:49 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//	calculate the zoom based on the mouse position
void	calculate_zoom_pos(t_window *window, double *zoom)
{
	double	zoom_x;
	double	zoom_y;
	double	new_len_x;
	double	new_len_y;

	if (*zoom == ZOOM_DEFAULT)
	{
		zoom_x = ZOOM_DEFAULT;
		zoom_y = ZOOM_DEFAULT;
		return ;
	}

	zoom_x = check_zoom_direction(window->map_sz.xposmw, window->mouse_posx, *zoom);
	zoom_y = check_zoom_direction(window->map_sz.yposmw, window->mouse_posy, *zoom);
	printf("x: %f, map: %d, mouse: %d\n", zoom_x, window->map_sz.xposmw, window->mouse_posx);
	printf("y: %f, map: %d, mouse: %d\n\n", zoom_y, window->map_sz.yposmw, window->mouse_posy);
	// if (((window->map_sz.maxsz_x_p * zoom_x) < MARGIN)
	// 	|| ((window->map_sz.maxsz_x_m * zoom_x) > (window->width - MARGIN))
	// 	|| ((window->map_sz.maxsz_y_m * zoom_y) < MARGIN)
	// 	|| ((window->map_sz.maxsz_y_p * zoom_y) > (window->height - MARGIN)))
	// {
	// 	*zoom = ZOOM_DEFAULT;
	// 	zoom_x = ZOOM_DEFAULT;
	// 	zoom_y = ZOOM_DEFAULT;
	// 	return ;
	// }
	new_len_x = (window->map_sz.xposmw - window->mouse_posx) * (ZOOM_DEFAULT - zoom_x);
	new_len_y = (window->map_sz.yposmw - window->mouse_posy) * (ZOOM_DEFAULT - zoom_y);
	printf("zoom_x:  %f zoom_y: %f lenx: %f, leny: %f\n", zoom_x, zoom_y, new_len_x, new_len_y);
	window->map_sz.xposmw += new_len_x;
	window->map_sz.yposmw += new_len_y;
	window->map_sz.xm_offset = -window->cent_xw + window->map_sz.xposmw;
	window->map_sz.ym_offset = -window->cent_yw + window->map_sz.yposmw;
	printf("new map x:map: %f\n", window->map_sz.xm_offset);
	printf("new map y:map: %f\n", window->map_sz.ym_offset);
}
