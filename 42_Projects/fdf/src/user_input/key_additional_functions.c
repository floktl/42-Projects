/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_additional_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 07:33:54 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/20 08:52:22 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//	this function resets the map settings to the default settings
int	reset_map(t_window *window)
{
	t_coord		*coord;
	static int	key_pressed = OFF;

	if (mlx_is_key_down(window->mlx, MLX_KEY_T) && key_pressed == OFF)
	{
		ft_printf("\033[0;35mReset map...\033[0m\n");
		clear_image(window, DEFAULT_WINDOW_COLOR);
		set_map_to_middle(window);
		reset_map_size(window);
		coord = window->coord;
		while (coord != NULL)
		{
			update_mapsize(&window->map_sz, coord);
			rotation_calc(window, coord);
			coord = coord->next;
		}
		return (key_pressed = ON, CHANGE);
	}
	else if (!mlx_is_key_down(window->mlx, MLX_KEY_T))
		key_pressed = OFF;
	return (NO_CHANGE);
}

//	this function enables the debug mode and resets the map with the key T
int	debug_mode_map(t_window *window)
{
	static int	key_pressed = OFF;

	if (mlx_is_key_down(window->mlx, MLX_KEY_D) && key_pressed == OFF)
	{
		if (window->debug_mode == OFF)
			window->debug_mode = ON;
		else if (window->debug_mode == ON)
			window->debug_mode = OFF;
		if (window->debug_mode == ON)
		{
			mlx_set_window_title(window->mlx, "fdf --DEBUG MODE ENABLED--");
			ft_printf("\033[0;33m\n\nDEBUG MODE ENABLED...\033[0m\n");
			ft_printf(
				"\033[0;35mAdjust the debug points as you like...\033[0m\n");
		}
		else
			mlx_set_window_title(window->mlx, "fdf");
		key_pressed = ON;
		return (CHANGE);
	}
	else if (!mlx_is_key_down(window->mlx, MLX_KEY_D))
		key_pressed = OFF;
	return (NO_CHANGE);
}

//	this function sets the map to the middle of the window
void	set_map_to_middle(t_window *window)
{
	window->map_sz.xposmw = window->width / 2;
	window->map_sz.yposmw = window->height / 2;
	window->map_sz.zcentmw = Z;
	window->map_sz.xm_rot_deg = DEGREE_DEFAULT_X;
	window->map_sz.ym_rot_deg = DEGREE_DEFAULT_Y;
	window->map_sz.zm_rot_deg = DEGREE_DEFAULT_Z;
}

int	information(t_window *window)
{
	static int	key_pressed = OFF;
	static int	information = OFF;

	if (mlx_is_key_down(window->mlx, MLX_KEY_I) && key_pressed == OFF)
	{
		if (information == OFF)
			information = ON;
		else if (information == ON)
			information = OFF;
		if (information == ON && window->width > 500 && window->height > 500)
		{

		}
		else
			mlx_set_window_title(window->mlx, "fdf");
		key_pressed = ON;
		return (CHANGE);
	}
	else if (!mlx_is_key_down(window->mlx, MLX_KEY_I))
		key_pressed = OFF;
	return (NO_CHANGE);
}
