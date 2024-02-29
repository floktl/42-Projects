/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:39:28 by fkeitel           #+#    #+#             */
/*   Updated: 2024/02/29 11:46:57 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//Point rotateY(Point p, double theta) {
//    Point pRotated;
//    double rad = theta * M_PI / 180.0; // Convert degrees to radians
//    pRotated.x = cos(rad) * p.x + sin(rad) * p.z;
//    pRotated.y = p.y; // Y-coordinate remains unchanged
//    pRotated.z = -sin(rad) * p.x + cos(rad) * p.z;
//    return pRotated;
//}

// formula to check, if a point is on a line between two points:
//		((Px - Ax)(By - Ay) - (Py -Ay)(Bx - Ax)) == 0 (A = cur, B = next)
// then a check if point is between the points A and B
//laslty calculate the z axis of P with , and dislpay it
void	connect_points(t_window *map, t_coord *cur, t_coord *next)
{
	int	x;
	int	y;
	int	z;
	int	x_set;
	int	y_set;

	y = 0;
	y_set = 0;
	if (cur->yw <= next->yw)
		y_set = cur->yw;
	else
		y_set = next->yw;
	if (cur->xw <= next->xw)
		x_set = cur->xw;
	else
		x_set = next->xw;
	y = y_set;
	while (y <= next->yw && (((y_set == cur->yw) && y <= next->yw)
			|| ((y_set == next->yw) && (y <= cur->yw))))
	{
		x = x_set;
		while (x <= next->xw)
		{
			if ((((x - cur->xw) * (next->yw - cur->yw)
						- (y - cur->yw) * (next->xw - cur->xw))
					== 0) && ((cur->xw <= x && x <= next->xw)
					|| (next->xw <= x && x <= cur->xw))
				&& ((cur->yw <= y && y <= next->yw)
					|| (next->yw <= y && y <= cur->yw))
				&& x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
			{
				z = calc_z(cur, next, x, y);
				mlx_put_pixel(map->image, x, y, ft_pixel(0xFF, 0xFF
						- (z * (255 / 10)), 0xFF - (z * (255 / 10)), 0xFF));
			}
			x++;
		}
		y++;
	}
}

double	radians(double degrees)
{
	return (degrees * 3.14159265358979323846 / 180.0);
}

void	find_new_point(double x1, double y1, double len_x_to_y, double deg)
{
	double angleRadians = radians(deg);
	double x2 =  x2 = x1 + len_x_to_y * cos(angleRadians);
	double y2 = y1 + len_x_to_y * sin(angleRadians);
	printf("New point is at (%.2f, %.2f)\n", x2, y2);
}
//hook functions for user input:
//user can rotate in all axis, or move the object in all directions
int	ft_hook(t_window *window)
{
	int		x_offset;
	int		y_offset;
	int		z_offset;
	int		zoom;

	x_offset = 0;
	y_offset = 0;
	z_offset = 0;
	zoom = 0;
	if (mlx_is_key_down(window->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(window->mlx);
	else if (mlx_is_key_down(window->mlx, MLX_KEY_UP))
		y_offset -= 15;
	else if (mlx_is_key_down(window->mlx, MLX_KEY_DOWN))
		y_offset += 15;
	else if (mlx_is_key_down(window->mlx, MLX_KEY_LEFT))
		x_offset -= 15;
	else if (mlx_is_key_down(window->mlx, MLX_KEY_RIGHT))
		x_offset += 15;
	else if (mlx_is_key_down(window->mlx, MLX_KEY_P))
	{
		if ((++window->zoom_factor) > 100)
			return (window->zoom_factor -= 1, 0);
	}
	else if (mlx_is_key_down(window->mlx, MLX_KEY_M))
	{
		if ((--window->zoom_factor) < 0)
			return (window->zoom_factor += 1, 0);
	}
	else if (mlx_is_key_down(window->mlx, MLX_KEY_Z))
	{
		window->debug_mode *= -1;
		if (window->debug_mode == 1)
			printf("Debug mode enabled");
		else
			printf("Debug mode off, press Z to enable");
	}
	//else if (mlx_is_key_down(window->mlx, MLX_KEY_T))
	//{
	//	set_coord(window);
	//}
	if ((x_offset == 0 && y_offset == 0 && z_offset == 0 && zoom == 0)
		&& range_check(window, &x_offset, &y_offset, &z_offset) == 0)
		return (0);
	clear_image(window->image, 0x00000000);
	update_coord(window, x_offset, y_offset, z_offset);
	return (1);
}

//fills the window with the map rendered in 3d
void	ft_render(void *param)
{
	t_window	*window;
	t_coord		*temp;
	t_coord		*middle = NULL;
	t_coord		*current;
	int			y;

	window = (t_window *)param;
	middle = malloc(sizeof(t_coord));
	ft_hook(window);
	current = window->coord;
	middle->xw = window->map_sz.xcentm + window->map_sz.xm_offset;
	middle->yw = window->map_sz.ycentm + window->map_sz.ym_offset;
	while (current != NULL && current->next != NULL)
	{
		connect_points(window, current, current->next);
		connect_points(window, current->next, middle);
		temp = current;
		y = 0;
		while (y++ < window->map_sz.xm_size && temp->next != NULL
			&& y % (window->map_sz.xm_size + 1) != 0)
			temp = temp->next;
		connect_points(window, current, temp);
		connect_points(window, middle, current->next_y);
		current = current->next;
	}
	free(&middle);
}
