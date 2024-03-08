/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:28:26 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/08 15:24:17 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// combines rgb and alpha(transparency) values into single color
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

//	assigns  the highest and lowest value of the map (z_direction) as well
//	as the the distance to the map middlepoint in z direction
void	find_highest_and_lowest(t_window *map)
{
	t_window	*temp;
	int			x;
	int			y;
	int			value;

	map->map_sz.zmcent_plus = atoi(map->map[0][0]);
	map->map_sz.zmcent_minus = atoi(map->map[0][0]);
	y = 0;
	temp = map;
	while (y < temp->map_sz.ym_size)
	{
		x = 0;
		while (x < temp->map_sz.xm_size)
		{
			value = atoi(map->map[y][x]);
			if (value > map->map_sz.zmcent_plus)
				map->map_sz.zmcent_plus = value;
			if (value < map->map_sz.zcentmw)
				map->map_sz.zcentmw = value;
			x++;
		}
		y++;
	}
}

//	adds a new coordinate to the existing one
void	ft_add_back(t_coord **lst, t_coord *new)
{
	t_coord	*current;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

//	save shutdown error for an error case
int	ft_shutdown_error(mlx_t *mlx)
{
	mlx_close_window(mlx);
	return (puts(mlx_strerror(mlx_errno)), -1);
}

//this function returns the zoom direction dpending on the mouse position
double	check_zoom_direction(int map_middle, int zoom_position, double zoom)
{
	double	zoom_direction;

	if (map_middle < zoom_position)
		zoom_direction = ZOOM_M;
	else if (map_middle > zoom_position)
		zoom_direction = ZOOM_P;
	else
		zoom_direction = ZOOM_DEFAULT;
	if (zoom == ZOOM_M)
	{
		if (zoom_direction == ZOOM_P)
			zoom_direction = ZOOM_M;
		else if (zoom_direction == ZOOM_M)
			zoom_direction = ZOOM_P;
	}
	return (zoom_direction);
}
