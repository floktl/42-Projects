/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:28:26 by fkeitel           #+#    #+#             */
/*   Updated: 2024/02/29 11:33:12 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// combines rgb and alpha(transparency) values into single color
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

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
			if (value < map->map_sz.zcentm)
				map->map_sz.zcentm = value;
			x++;
		}
		y++;
	}
}

void	ft_add_back(t_coord **lst, t_coord *new)
{
	t_coord	*current;
	t_coord	*current_y;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->before = current;
	if (new->next_y != NULL)
	{
		current_y = *lst;
		while (current_y->next_y != NULL)
			current_y = current_y->next_y;
		current_y->next_y = new;
		new->before_y = current_y;
	}
}

int	ft_shutdown_error(mlx_t *mlx)
{
	mlx_close_window(mlx);
	return (puts(mlx_strerror(mlx_errno)), -1);
}
