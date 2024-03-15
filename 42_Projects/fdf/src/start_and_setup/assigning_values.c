/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 07:33:01 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/15 11:27:07 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//---------------- functions to assign the data for the structs ---------------
//

//----------------------------- window struct ----------------------------------

//	sets the default settings for the window
int	set_default_window_data(t_window *window)
{
	if (!window)
		return (EXIT_FAILURE);
	window->start_size = (WIDTH / (window->map_sz.xm_size + 2));
	window->cent_xw = WIDTH / 2;
	window->cent_yw = HEIGHT / 2;
	window->map_sz.xm_offset = OFFSET_DEFAULT;
	window->map_sz.ym_offset = OFFSET_DEFAULT;
	window->map_sz.zm_offset = OFFSET_DEFAULT;
	window->debug_mode = -1;
	window->width = WIDTH;
	window->height = HEIGHT;
	window->zoom = ZOOM_DEFAULT;
	window->max_zoom_size = WIDTH * HEIGHT * MAX_MAP_SIZE;
	window->min_zoom_size = (WIDTH * HEIGHT) / MIN_MAP_SIZE;
	return (0);
}

//-------------------------------- map structs ---------------------------------

//	sets the default settings for the map after start-up
int	map_size_default_setting(t_sz *map_sz, t_sz size)
{
	map_sz->xposmw = WIDTH / 2;
	map_sz->yposmw = HEIGHT / 2;
	map_sz->zcentmw = 0;
	map_sz->xm_rot_deg = DEGREE_DEFAULT_X;
	map_sz->ym_rot_deg = DEGREE_DEFAULT_Y;
	map_sz->zm_rot_deg = DEGREE_DEFAULT_Z;
	map_sz->xm_size = size.xm_size;
	map_sz->ym_size = size.ym_size;
	map_sz->maxsz_x_p = map_sz->xposmw;
	map_sz->maxsz_x_m = map_sz->xposmw;
	map_sz->maxsz_y_p = map_sz->yposmw;
	map_sz->maxsz_y_m = map_sz->yposmw;
	map_sz->maxsz_z_p = 0;
	map_sz->maxsz_z_m = 0;
	return (0);
}

//------------------------------ coord structs --------------------------------

// this function set all important variables into struct to each point in a loop
int32_t	set_coord(t_window *window)
{
	t_coord	*coord;
	int		x_axis;
	int		y_axis;
	t_coord	*next_coordinate;

	y_axis = 0;
	coord = NULL;
	printf("\033[0;35mAssigning coordinate data...\033[0m\n");
	while (y_axis < window->map_sz.ym_size)
	{
		x_axis = 0;
		while (x_axis < window->map_sz.xm_size)
		{
			next_coordinate = link_add_pt(&coord, window, x_axis, y_axis);
			if (!next_coordinate)
				return (free(next_coordinate), EXIT_FAILURE);
			assign_coord_position(window, next_coordinate, x_axis, y_axis);
			update_mapsize(&window->map_sz, next_coordinate);
			assign_degree_len_color(window, next_coordinate, x_axis, y_axis);
			x_axis++;
		}
		y_axis++;
	}
	ft_set_after_y(coord, window);
	window->coord = coord;
	return (EXIT_SUCCESS);
}

//	assign the position of the coordinates on the map and the window
int	assign_coord_position(t_window *window, t_coord *coord, int x, int y)
{
	double	round_x;
	double	round_y;
	double	default_offset_x;
	double	default_offset_y;

	round_x = 0.0;
	if (window->map_sz.xm_size % 2 == 1)
		round_x = 0.5;
	round_y = 0.0;
	if (window->map_sz.ym_size % 2 == 1)
		round_y = 0.5;
	default_offset_x = -((window->map_sz.xm_size * window->start_size) / 2)
		+ ((x + round_x) * window->start_size);
	default_offset_y = ((window->map_sz.ym_size * window->start_size) / 2)
		- ((y + round_y) * window->start_size);
	coord->xm = default_offset_x;
	coord->ym = default_offset_y;
	coord->zm = window->map[y][x][0] + window->map_sz.zm_offset;
	coord->xw = ft_round(coord->xm) + window->cent_xw;
	coord->yw = -ft_round(coord->ym) + window->cent_yw;
	coord->zw = ft_round(coord->zm) + 0;
	return (0);
}

void	assign_color(t_window *window, t_coord *coord, int x, int y)
{
	if (window->map[y][x][1] == 0)
	{
		if (coord->zm == 0)
			coord->color = COLOR_DEFAULT_CEN;
		else if (coord->zm == window->map_sz.zmcent_plus)
			coord->color = COLOR_DEFAULT_PLUS;
		else if (coord->zm == window->map_sz.zmcent_minus)
			coord->color = COLOR_DEFAULT_MIN;
		else if (coord->zm > 0)
		{
			coord->color = find_color(COLOR_DEFAULT_CEN, COLOR_DEFAULT_PLUS,
					(float)(coord->zm) / (window->map_sz.zmcent_plus));
		}
		else if (coord->zm < 0)
		{
			coord->color = find_color(COLOR_DEFAULT_CEN, COLOR_DEFAULT_MIN,
					(float)(coord->zm) / (window->map_sz.zmcent_minus));
		}
	}
	else
		coord->color = window->map[y][x][1] << 8;
	coord->color += BRIGHTNESS_DEFAULT;
}

//	polarAngle corresponds to the inclination or zenith angle.
//	azimuthalAngle corresponds to the angle measured in the x-y plane.
//	additionalAngle correspond to the third angle representing rotation or tilt.
int	assign_degree_len_color(t_window *window, t_coord *coord, int x, int  y)
{
	double	dist_to_map_center;

	dist_to_map_center = ft_sqrt((coord->xm * coord->xm)
			+ (coord->ym * coord->ym) + (coord->zm * coord->zm));
	coord->deg_xm = calc_angle(coord->xm, coord->ym);
	coord->deg_ym = calc_angle(coord->ym, coord->xm);
	coord->deg_zm = calc_angle(coord->ym, coord->zm);
	coord->len_cent = dist_to_map_center;
	assign_color(window, coord, x, y);
	return (0);
}
