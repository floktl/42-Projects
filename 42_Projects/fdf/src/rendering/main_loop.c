/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:45:33 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/09 15:03:25 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	check_margin_border(t_window *window)
{
	if (window->mouse_posx < 0 || window->mouse_posx > window->width
		|| window->mouse_posy < 0 || window->mouse_posy > window->height)
	{
		window->mouse_posx = window->cent_xw;
		window->mouse_posy = window->cent_xw;
		return (1);
	}
	return (0);
}

//fills the window with the map rendered in 3d
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
		print_debug_point(window);
	}
	current = window->coord;
	while (current != NULL && current->next != NULL)
	{
		if (current->pos_ym == current->next->pos_ym)
			connect_points(window, current, current->next);
		connect_points(window, current, current->next_y);
		current = current->next;
	}
}
