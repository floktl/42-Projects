/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:24:45 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/07 16:34:12 by fkeitel          ###   ########.fr       */
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
	check_if_zoomed(window, x_set, y_set, zoom);
	map_sz->maxsz_x_p = 0;
	map_sz->maxsz_x_m = 0;
	map_sz->maxsz_y_p = 0;
	map_sz->maxsz_y_m = 0;
	while (temp != NULL)
	{
		update_mapsize(&window->map_sz, temp);
		zoom_calc(window, temp, zoom);
		temp->xw += x_set;
		temp->yw -= y_set;
		temp = temp->next;
	}
	print_stacks(window);
	return (EXIT_SUCCESS);
}
