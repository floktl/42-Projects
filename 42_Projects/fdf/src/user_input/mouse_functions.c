/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:58:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/09 21:12:16 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//------ these fucntions handles the calclualtion for mouse user input --------
//

//	checks if the mouse button clicked and the pointer in the image
int	check_mouse_clicked(t_window *window, int x, int y)
{

	if (mlx_is_mouse_down(window->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		if (x > 0 && x < window->width && y > 0 && y < window->height)
		{
			return (1);
		}
	}
	return (0);
}

//	calculates the shift of the map, with the left button clicked
int	mouse_shift(t_window *window, int *x_set, int *y_set)
{
	static int	previous_x = 0;
	static int	previous_y = 0;
	int			x;
	int			y;

	mlx_get_mouse_pos(window->mlx, &x, &y);
	if (check_mouse_clicked(window, x, y) == 1)
	{
		x -= previous_x;
		y -= previous_y;
		x = range_check(window, x, 0, 0);
		y = range_check(window, 0, y, 0);
	}
	else
	{
		x = 0;
		y = 0;
	}
	previous_x = window->mouse_posx;
	previous_y = window->mouse_posy;
	*x_set += x;
	*y_set += y;
	return (0);
}
