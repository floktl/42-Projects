/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:11:17 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/18 09:18:03 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//	functions, that will handle all keypads and mouse inputs from the user
//

int	check_change_height(t_window *window)
{
	static double	prev_height = ZOOM_DEFAULT;

	if (window->map_sz.height_change == prev_height)
		return (0);
	else
	{
		prev_height = window->map_sz.height_change;
		return (1);
	}
}

//	this function checks, if there is a change in the rotation from user input
int	check_change_in_rotation(t_window *window)
{
	static double	prev_rot_x = ZOOM_DEFAULT;
	static double	prev_rot_y = ZOOM_DEFAULT;
	static double	prev_rot_z = ZOOM_DEFAULT;

	if (window->map_sz.xm_rot_deg == prev_rot_x
		&& window->map_sz.ym_rot_deg == prev_rot_y
		&& window->map_sz.zm_rot_deg == prev_rot_z)
		return (0);
	else
	{
		prev_rot_x = window->map_sz.xm_rot_deg;
		prev_rot_y = window->map_sz.ym_rot_deg;
		prev_rot_z = window->map_sz.zm_rot_deg;
		return (1);
	}
}

//	hook functions for keyboard user input:
//	arrow keys: moving map in x and y direction
//	P: Zoom in M: Zoom out
//	R + arrow keys: rotate map in x and y direction
//	D: Debug mode with terminal value view option and map center visualization
int	ft_hook_key(t_window *window, int *x_set, int *y_set)
{
	if (mlx_is_key_down(window->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(window->mlx);
	debug_mode_map(window);
	change_height_map(window);
	shift_map(window, x_set, y_set);
	mouse_shift(window, x_set, y_set);
	mouse_rotation(window);
	zoom_map(window);
	rotate_map(window);
	if (window->zoom == ZOOM_DEFAULT && *x_set == 0 && *y_set == 0
		&& check_change_in_rotation(window) == 0
		&& check_change_height(window) == 0)
		return (0);
	return (1);
}
