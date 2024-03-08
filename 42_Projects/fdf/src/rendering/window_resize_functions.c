/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_resize_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:45:17 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/08 11:51:33 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	ft_resize(int width, int height, void *param)
{
	t_window	*window;

	window = (t_window *)param;
	clear_image(window, 0x00000000);
	if (width > window->width || height > window->height)
		mlx_resize_image(window->image, width, height);
	window->width = width;
	window->height = height;
	window->cent_xw = width / 2;
	window->cent_yw = height / 2;
	window->map_sz.xm_offset = window->map_sz.xposmw - window->cent_xw;
	window->map_sz.ym_offset = window->cent_yw - window->map_sz.yposmw;
	print_stacks(window);
}
