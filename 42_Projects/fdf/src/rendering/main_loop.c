/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:45:33 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/07 15:18:08 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//fills the window with the map rendered in 3d
void	ft_render(void *param)
{
	t_window	*window;
	t_coord		*current;
	int			x_offset;
	int			y_offset;
	double		zoom;

	x_offset = 0;
	y_offset = 0;
	zoom = 0;
	window = (t_window *)param;
	if (ft_hook_key(window, &x_offset, &y_offset, &zoom) == 1)
	{
		clear_image(window, 0x00000000);
		update_coord(window, x_offset, y_offset, zoom);
	}
	current = window->coord;
	print_debug_point(window);
	while (current != NULL && current->next != NULL)
	{
		if (current->pos_ym == current->next->pos_ym)
			connect_points(window, current, current->next);
		connect_points(window, current, current->next_y);
		current = current->next;
	}
}
