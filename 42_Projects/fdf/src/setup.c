/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:28:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/02/29 12:05:44 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	get_array_size(t_window *window)
{
	t_sz		size;
	t_window	*temp;

	size.ym_size = 0;
	window->map_sz.xcentm = 0;
	window->map_sz.ycentm = 0;
	window->map_sz.zcentm = 0;
	window->map_sz.xm_rot_deg = 0;
	window->map_sz.ym_rot_deg = 0;
	window->map_sz.zm_rot_deg = 0;
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

t_coord *ft_get_at_index(t_coord *head, int index, t_coord **before)
{
    if (head == NULL || index < 0)
        return NULL;  // Invalid input

    int count = 0;
    t_coord *current = head;
    *before = NULL;  // Initialize the 'before' pointer

    while (current != NULL)
    {
        if (count == index)
            return current;  // Found the desired index

        *before = current;
        current = current->next;
        count++;
    }

    *before = NULL;  // Index out of bounds
    return NULL;
}



// this function set all important variables into struct to each point in a loop
t_window	*set_coord(t_window *window)
{
	t_coord	*coordinates;
	t_coord	*new;
	int		x_axis;
	int		y_axis;

	y_axis = 0;
	coordinates = NULL;
	while (y_axis < window->map_sz.ym_size)
	{
		x_axis = 0;
		while (x_axis < window->map_sz.xm_size)
		{
			new = malloc(sizeof(t_coord));
			if (!new)
				return (perror("Memory allocation error"), NULL);
			new->pos_xm = x_axis + 1;
			new->pos_ym = y_axis + 1;
			new->xm_xmcent = (x_axis * window->start_size)
				- (window->map_sz.xm_size * window->start_size) / 2;
			new->ym_ymcent = (y_axis * window->start_size)
				- (window->map_sz.ym_size * window->start_size) / 2;
			new->zm_zmcent = ft_atoi(window->map[y_axis][x_axis])
				+ window->map_sz.zm_offset;
			new->xw = new->xm_xmcent + window->map_sz.xm_offset;
			new->yw = new->ym_ymcent + window->map_sz.ym_offset;
			new->zw = new->zm_zmcent + window->map_sz.zm_offset;
			new->deg_cmx_xm = calc_angle(new->xm_xmcent, new->ym_ymcent, 'X');
			new->deg_cmy_ym = calc_angle(new->ym_ymcent, new->xm_xmcent, 'Y');
			new->deg_cmz_zm = calc_angle(new->ym_ymcent, new->zm_zmcent, 'Z');
			new->len_cent = ft_sqrt((new->xm_xmcent * new->xm_xmcent)
					+ (new->ym_ymcent * new->ym_ymcent)
					+ (new->zm_zmcent * new->zm_zmcent));
			new->color = ft_pixel(0xFF, 0xFF
					- (new->zw * (255 / (window->map_sz.zmcent_plus + 1))), 0xFF
					- (new->zw * (255 / (window->map_sz.zmcent_minus - 1))), 0xFF);
			new->next = NULL;
			new->next_y = NULL;
			new->before_y = NULL;
			if (y_axis < (window->map_sz.ym_size - 1))
			{
				int index_next_y = (y_axis + 1) * window->map_sz.xm_size + x_axis;

				t_coord *next_y = ft_get_at_index(coordinates, index_next_y, &new->before);

				if (next_y != NULL)
				{
					new->next_y = next_y;
					next_y->before_y = new;
					if (new->before != NULL)
					{
						new->before->next = new;
					}
					if (x_axis == 0)
						new->before = NULL;
				}
			}
			ft_add_back(&coordinates, new);
			x_axis++;
		}
		y_axis++;
	}
	window->coord = coordinates;
	//if (window->debug_mode == 1)
	print_stacks(window);
	return (EXIT_SUCCESS);
}

//this function updates all important variables to each point in map
int32_t	update_coord(t_window *window, int x_set, int y_set, int z_set)
{
	t_coord		*temp;

	temp = window->coord;
	if (window->zoom_factor == window->last_zoom_faktor)
	{
		window->map_sz.xm_offset += x_set;
		window->map_sz.ym_offset += y_set;
		window->map_sz.zm_offset += z_set;
	}
	while (temp != NULL)
	{
		zoom_calc(window, temp);
		temp->xw += x_set;
		temp->yw += y_set;
		temp->zw += z_set;
		temp = temp->next;
	}
	if (window->debug_mode == 1)
		print_stacks(window);
	return (EXIT_SUCCESS);
}
