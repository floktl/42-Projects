/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:45:33 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/12 20:10:38 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//-------------- main loop for the programm, it runs constantly----------------
//

//fills the window with the map rendered in 3d functionality
void	ft_render(void *param)
{
	t_window	*window;
	t_coord		*current;
	int			x_offset;
	int			y_offset;

	x_offset = 0;
	y_offset = 0;
	window = (t_window *)param;
	mlx_get_mouse_pos(window->mlx, &window->mouse_posx, &window->mouse_posy);
	check_margin_border(window);
	if (ft_hook_key(window, &x_offset, &y_offset) == 1)
	{
		clear_image(window, 0x00000000);
		update_coord(window, x_offset, y_offset);
	}
	print_debug_point_1(window);
	current = window->coord;
	while (current != NULL && current->next != NULL)
	{
		if (current->pos_ym == current->next->pos_ym)
			connect_points(window, current, current->next);
		connect_points(window, current, current->next_y);
		current = current->next;
	}
}
