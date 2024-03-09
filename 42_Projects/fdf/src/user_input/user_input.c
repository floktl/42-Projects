/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:11:17 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/09 15:05:58 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//	functions, that will handle all keypads and mouse inputs from the user
//

// hook functions for keyboard user input:
//	arrow keys: moving map in x amd y direction
//	P: Zoom in M: Zoom out
//	R + arrow keys: rotate map in x and y direction
//	D: Debug mode with terminal value view option and map center visualization
int	ft_hook_key(t_window *window, int *x_set, int *y_set)
{
	if (mlx_is_key_down(window->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(window->mlx);
	debug_mode_map(window);
	shift_map(window, x_set, y_set);
	mouse_shift(window, x_set, y_set);
	zoom_map(window);
	if (window->zoom == ZOOM_DEFAULT && *x_set == 0 && *y_set == 0)
		return (0);
	return (1);
}
