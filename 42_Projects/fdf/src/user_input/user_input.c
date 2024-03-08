/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:11:17 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/08 15:25:47 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//	functions, that will handle all keypads and mouse inputs from the user
//

int	shift_map(t_window *window, int *x_set, int *y_set, int *key_pressed)
{
	int	speed;

	speed = 15 * (window->height + window->width) / (HEIGHT + WIDTH);
	if (mlx_is_key_down(window->mlx, MLX_KEY_UP))
	{
		*y_set = range_check(window, 0, -speed, 0);
		*key_pressed = 1;
	}
	if (mlx_is_key_down(window->mlx, MLX_KEY_DOWN))
	{
		*y_set = range_check(window, 0, speed, 0);
		*key_pressed = 1;
	}
	if (mlx_is_key_down(window->mlx, MLX_KEY_LEFT))
	{
		*x_set = range_check(window, -speed, 0, 0);
		*key_pressed = 1;
	}
	if (mlx_is_key_down(window->mlx, MLX_KEY_RIGHT))
	{
		*x_set = range_check(window, speed, 0, 0);
		*key_pressed = 1;
	}
	if (!key_pressed)
		return (0);
	return (1);
}

double	zoom_map(t_window *window, int *key_pressed, double *zoom)
{
	float	map_size;
	float	max_size;
	float	min_size;

	map_size = (window->map_sz.maxsz_x_p - window->map_sz.maxsz_x_m)
		* (window->map_sz.maxsz_y_m - window->map_sz.maxsz_y_p);
	max_size = (window->mlx->width * window->mlx->height) * 6;
	min_size = (window->mlx->width * window->mlx->height) / 20;
	//printf("map: %f, max: %f, min: %f", map_size, max_size, min_size);
	if (mlx_is_key_down(window->mlx, MLX_KEY_P)
			&& !mlx_is_key_down(window->mlx, MLX_KEY_M))
	{
		*key_pressed = 1;
		if (map_size * ZOOM_P < max_size)
			*zoom = ZOOM_P;
	}
	else if (mlx_is_key_down(window->mlx, MLX_KEY_M)
			&& !mlx_is_key_down(window->mlx, MLX_KEY_P))
	{
		*key_pressed = 1;
		if (map_size * ZOOM_M > min_size)
			*zoom = ZOOM_M;
	}
	else
		*zoom = ZOOM_DEFAULT;
	return (0);
}

int	debug_mode_map(t_window *window)
{
	static int	key_pressed = 0;

	if (mlx_is_key_down(window->mlx, MLX_KEY_D) && !key_pressed)
	{
		window->debug_mode *= -1;
		if (window->debug_mode == 1)
			mlx_set_window_title(window->mlx, "fdf --DEBUG MODE ENABLED--");
		else
			mlx_set_window_title(window->mlx, "fdf");
		key_pressed = 1;
		return (1);
	}
	else if (!mlx_is_key_down(window->mlx, MLX_KEY_D))
		key_pressed = 0;
	if (mlx_is_key_down(window->mlx, MLX_KEY_T))
	{
		clear_image(window, 0x00000000);
		set_coord(window);
		return (1);
	}
	return (0);
}

// hook functions for keyboard user input:
//	arrow keys: moving map in x amd y direction
//	P: Zoom in M: Zoom out
//	R + arrow keys: rotate map in x and y direction
//	D: Debug mode with terminal value view option and map center visualization
//	range check, to avoid moving object out of visible window area
int	ft_hook_key(t_window *window, int *x_set, int *y_set, double *zoom)
{
	int	key_pressed = 0;

	if (mlx_is_key_down(window->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(window->mlx);
	debug_mode_map(window);
	shift_map(window, x_set, y_set, &key_pressed);
	zoom_map(window, &key_pressed, zoom);
	if (!key_pressed)
		return (0);
	else
		return (1);
}
