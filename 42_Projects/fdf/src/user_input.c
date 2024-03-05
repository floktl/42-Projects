/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:11:17 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/05 09:37:46 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//
//	functions, that will handle all keypads and mouse inputs from the user
//

// hook functions for keyboard user input:
//	arrow keys: moving map in x amd y direction
//	P: Zoom in M: Zoom out
//	R + arrow keys: rotate map in x and y direction
//	D: Debug mode with terminal value view option and map center visualization
//	range check, to avoid moving object out of visible window area
int	ft_hook_key(t_window *window, int *x_set, int *y_set, int *z_set)
{
	int	key_pressed;
	int	speed;

	key_pressed = 0;
	*z_set = *z_set;
	speed = 15 * (window->height + window->width) / (HEIGHT + WIDTH);
	if (mlx_is_key_down(window->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(window->mlx);
	if (mlx_is_key_down(window->mlx, MLX_KEY_UP))
	{
		*y_set = range_check(window, 0, speed, 0);
		key_pressed = 1;
	}
	if (mlx_is_key_down(window->mlx, MLX_KEY_DOWN))
	{
		*y_set = range_check(window, 0, -speed, 0);
		key_pressed = 1;
	}
	if (mlx_is_key_down(window->mlx, MLX_KEY_LEFT))
	{
		*x_set = range_check(window, -speed, 0, 0);
		key_pressed = 1;
	}
	if (mlx_is_key_down(window->mlx, MLX_KEY_RIGHT))
	{
		*x_set = range_check(window, speed, 0, 0);
		key_pressed = 1;
	}
	if (mlx_is_key_down(window->mlx, MLX_KEY_P))
	{
		key_pressed = 1;
		window->zoom_factor++;
		if ((++window->zoom_factor) >= 97)
			return (window->zoom_factor -= 2, 1);
	}
	if (mlx_is_key_down(window->mlx, MLX_KEY_M))
	{
		key_pressed = 1;
		window->zoom_factor--;
		if ((--window->zoom_factor) <= 3)
			return (window->zoom_factor += 2, 1);
	}
	if (mlx_is_key_down(window->mlx, MLX_KEY_D))
	{
		window->debug_mode *= -1;
		if (window->debug_mode == 1)
			printf("Debug mode enabled");
		else
			printf("Debug mode off, press Z to enable");
		return (0);
	}
	if (mlx_is_key_down(window->mlx, MLX_KEY_T))
	{
		clear_image(window, 0x00000000);
		set_coord(window);
	}
	if (*x_set == 0 && *y_set == 0 && window->zoom_factor == window->last_zoom_faktor)
		return (0);
	return (1);
}

//fills the window with the map rendered in 3d
void	ft_render(void *param)
{
	t_window	*window;
	t_coord		*current;
	int			x_offset;
	int			y_offset;
	int			z_offset;

	x_offset = 0;
	y_offset = 0;
	z_offset = 0;
	window = (t_window *)param;
	if (ft_hook_key(window, &x_offset, &y_offset, &z_offset) == 1)
	{
		clear_image(window, 0x00000000);
		update_coord(window, x_offset, y_offset, z_offset);
	}
	current = window->coord;
	while (current != NULL)
	{
		connect_points(window, current, current->next);
		connect_points(window, current, current->next_y);
		current = current->next;
	}
}
