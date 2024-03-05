/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:28:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/05 10:09:22 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//
//	functions for the standard view of the map on the image
//

//	this function assigns all variable values of the map, which will change, but
// only for all coordinates at once, not every unique coordinate
void	get_array_size(t_window *window)
{
	t_sz		size;
	t_window	*temp;

	size.ym_size = 0;
	window->map_sz.xposmw = WIDTH / 2;
	window->map_sz.yposmw = HEIGHT / 2;
	window->map_sz.zcentmw = 0;
	window->map_sz.xm_rot_deg = 0;
	window->map_sz.ym_rot_deg = 0;
	window->map_sz.zm_rot_deg = 0;
	window->map_sz.maxsz_x_p = 0;
	window->map_sz.maxsz_x_m = 0;
	window->map_sz.maxsz_x_p = 0;
	window->map_sz.maxsz_x_m = 0;
	temp = window;
	while (temp->map[size.ym_size] != NULL)
		size.ym_size++;
	if (temp->map[0] != NULL)
	{
		size.xm_size = 0;
		while (temp->map[0][size.xm_size] != NULL)
			size.xm_size++;
	}
	window->map_sz.xm_size = size.xm_size;
	window->map_sz.ym_size = size.ym_size;
	find_highest_and_lowest(window);
}

// the name explain itself, this function reads the map data from the fdf file,
// and handles errors, returns the map
char	***read_and_split_lines(int fd)
{
	char	***lines_tokens;
	char	*line;
	int		count;

	count = 0;
	lines_tokens = malloc((MAX_LINES + 1) * sizeof(char **));
	if (!lines_tokens)
		return (perror("Failed to allocate memory for line tokens"), NULL);
	line = get_next_line(fd);
	while ((line))
	{
		lines_tokens[count] = ft_split(line, ' ');
		free(line);
		if (!lines_tokens[count])
		{
			while (--count >= 0)
				free(lines_tokens[count]);
			return (free(lines_tokens), NULL);
		}
		if (count++ < MAX_LINES)
			line = get_next_line(fd);
		else
			break ;
	}
	return (lines_tokens);
}

//	this function returns a new coordinate to the map and links the 4 neighbour
//	coordinates (in x and y direction)
t_coord	*link_add_pt(t_coord **coord, t_window *window, int x, int y)
{
	static t_coord	*last = NULL;
	t_coord			*new_coord;

	new_coord = malloc(sizeof(t_coord));
	if (!new_coord)
		return (NULL);
	new_coord->next = NULL;
	new_coord->next_y = NULL;
	new_coord->pos_xm = x + 1;
	new_coord->pos_ym = y + 1;
	if (new_coord->pos_xm == 1)
		new_coord->before = NULL;
	else
		new_coord->before = last;
	ft_add_back(coord, new_coord);
	if (new_coord->pos_ym < 1)
		new_coord->before_y = NULL;
	else
		ft_set_before_y(coord, get_index(window, new_coord->pos_xm,
				new_coord->pos_ym - 1), window);
	last = new_coord;
	return (new_coord);
}

// this function assign all start values to the coordinates, such as position on
//	the map, color, degrees, everything is viewed from middlepoint of the map
void	initialize_coord(t_coord *new, int x_axis, int y_axis, t_window *window)
{
	double	round_x;
	double	round_y;

	round_x = 0.0;
	if (window->map_sz.xm_size % 2 == 1)
		round_x = 0.5;
	round_y = 0.0;
	if (window->map_sz.ym_size % 2 == 1)
		round_y = 0.5;
	new->xm = -((window->map_sz.xm_size * window->zoom_factor) / 2)
		+ ((x_axis + round_x) * window->zoom_factor);
	new->ym = ((window->map_sz.ym_size * window->zoom_factor) / 2)
		- ((y_axis + round_y) * window->zoom_factor);
	new->zm = ft_atoi(window->map[y_axis][x_axis])
		+ window->map_sz.zm_offset;
	new->xw = new->xm + window->cent_xw;
	new->yw = -new->ym + window->cent_yw;
	new->zw = new->zm + 0;
	if (window->map_sz.maxsz_x_p < new->xm)
		window->map_sz.maxsz_x_p = new->xm;
	if (window->map_sz.maxsz_x_m > new->xm)
		window->map_sz.maxsz_x_m = new->xm;
	if (window->map_sz.maxsz_y_p < new->ym)
		window->map_sz.maxsz_y_p = new->ym;
	if (window->map_sz.maxsz_y_m > new->ym)
		window->map_sz.maxsz_y_m = new->ym;
	new->deg_xm = calc_angle(new->xm, new->ym, 'X');
	new->deg_ym = calc_angle(-new->ym, new->xm, 'Y');
	new->deg_zm = calc_angle(new->ym, new->zm, 'Z');
	new->len_cent = ft_sqrt((new->xm * new->xm)
			+ (new->ym * new->ym)
			+ (new->zm * new->zm));
	new->color = ft_pixel(0xFF, 0xFF
			- (new->zm * (255 / (window->map_sz.zmcent_plus + 1))),
			0xFF - (new->zm * (255 / (window->map_sz.zmcent_minus - 1))), 0xFF);
}

//polarAngle corresponds to the inclination or zenith angle.
//azimuthalAngle corresponds to the angle measured in the x-y plane.
//additionalAngle corresponds to the third angle representing rotation or tilt.

// this function set all important variables into struct to each point in a loop
int32_t	set_coord(t_window *window)
{
	t_coord	*coord;
	int		x_axis;
	int		y_axis;
	t_coord	*next_coordinate;

	y_axis = 0;
	coord = NULL;
	while (y_axis < window->map_sz.ym_size)
	{
		x_axis = 0;
		while (x_axis < window->map_sz.xm_size)
		{
			next_coordinate = link_add_pt(&coord, window, x_axis, y_axis);
			if (!next_coordinate)
				return (free(next_coordinate), EXIT_FAILURE);
			initialize_coord(next_coordinate, x_axis, y_axis, window);
			x_axis++;
		}
		y_axis++;
	}
	ft_set_after_y(coord, window);
	window->coord = coord;
	print_stacks(window);
	return (EXIT_SUCCESS);
}
