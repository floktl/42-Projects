/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_resize_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:45:17 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/18 21:10:51 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//---------------------- functions for window rezising ------------------------
//

//	this functions updates the window struct, when the window size is changed
void	ft_resize(int width, int height, void *param)
{
	t_window	*window;

	window = (t_window *)param;
	clear_image(window, DEFAULT_WINDOW_COLOR);
	if (width > window->width || height > window->height)
		mlx_resize_image(window->image, width, height);
	window->width = width;
	window->height = height;
	window->cent_xw = width / 2;
	window->cent_yw = height / 2;
	window->map_sz.xm_offset = window->map_sz.xposmw - window->cent_xw;
	window->map_sz.ym_offset = window->cent_yw - window->map_sz.yposmw;
	window->max_zoom_size = (window->mlx->width * window->mlx->height)
		* MAX_MAP_SIZE;
	window->min_zoom_size = (window->mlx->width * window->mlx->height)
		/ MIN_MAP_SIZE;
	print_stacks(window);
}