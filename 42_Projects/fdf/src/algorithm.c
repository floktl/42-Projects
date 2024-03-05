/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:39:28 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/05 15:05:41 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//
//	this functions calculate the changes in the coordinates after the user input
//

//	function to check, if a point is on a line between two points:
//	((Px - Ax)(By - Ay) - (Py -Ay)(Bx - Ax)) == 0 (A = cur, B = next)
//	then a check if point is between the points A and B
//	laslty calculate the z axis of P with , and dislpay it
void	connect_points(t_window *window, t_coord *cur, t_coord *next)
{
	int	x;
	int	y;
	int	x_set;
	int	y_set;
	int	z;

	if (window == NULL || next == NULL)
		return ;
	y_set = next->yw;
	if (cur->yw <= next->yw)
		y_set = cur->yw;
	x_set = next->xw;
	if (cur->xw <= next->xw)
		x_set = cur->xw;
	y = y_set;
	while (y <= next->yw && (((y_set == cur->yw) && y <= next->yw)
			|| ((y_set == next->yw) && (y <= cur->yw))))
	{
		x = x_set;
		while (x <= next->xw)
		{
			if (x >= 0 && x < window->width && y >= 0 && y < window->height)
			{
				z = calc_z(cur, next, x, y);
				mlx_put_pixel(window->image, x, y, ft_pixel(0xFF, 0xFF
						- (z * (255 / 10)), 0xFF - (z * (255 / 10)), 0xFF));
			}
			x++;
		}
		y++;
	}
}

double	check_zoom_direction(int num)
{
	if (num < 0)
		return (0.9);
	else
		return (1.1);
}

//this function updates all important variables to each point in map
int32_t	update_coord(t_window *window, int x_set, int y_set, int z_set)
{
	t_coord		*temp;
	int			zoom_factor;
	double		dx;
	double		dy;
	double		zoom;

	zoom_factor = window->zoom_factor - window->last_zoom_faktor;
	temp = window->coord;
	if (zoom_factor == 0)
	{
		window->map_sz.xm_offset += x_set;
		window->map_sz.ym_offset += y_set;
		window->map_sz.zm_offset += z_set;
		window->map_sz.xposmw += x_set;
		window->map_sz.yposmw -= y_set;
		zoom = 0;
	}
	else
	{
		if (zoom_factor > 0)
			zoom = 1.1;
		else
			zoom = 0.9;
		dx = check_zoom_direction(window->map_sz.xposmw - window->mouse_posx);
		dy = check_zoom_direction(window->map_sz.yposmw - window->mouse_posy);
		if (zoom == 1.1)
		{
			if (dy == 1.1 && dx == 1.1)
			{
				dy = 1.1;
				dx = 1.1;
			}
			else if (dy == 1.1 && dx == 0.9)
			{
				dx = 0.9;
				dy = 1.1;
			}
			else if (dy == 0.9 && dx == 0.9)
			{
				dx = 0.9;
				dy = 0.9;
			}
			else if (dy == 0.9 && dx == 1.1)
			{
				dx = 1.1;
				dy = 0.9;
			}
		}
		else if (zoom == 0.9)
		{
			if (dy == 0.9 && dx == 0.9)
			{
				dy = 0.9;
				dx = 0.9;
			}
			else if (dy == 0.9 && dx == 1.1)
			{
				dx = 1.1;
				dy = 0.9;
			}
			else if (dy == 1.1 && dx == 1.1)
			{
				dx = 1.1;
				dy = 1.1;
			}
			else if (dy == 1.1 && dx == 0.9)
			{
				dx = 0.9;
				dy = 1.1;
			}
		}
		// window->map_sz.xm_offset *= dx;
		// window->map_sz.ym_offset *= dy;
		// window->map_sz.xposmw += window->map_sz.xm_offset;
		// window->map_sz.yposmw += window->map_sz.ym_offset;
	}
		zoom_factor = window->zoom_factor - window->last_zoom_faktor;
	while (temp != NULL)
	{
		zoom_calc(window, temp, zoom);
		temp->xw += x_set;
		temp->yw -= y_set;
		temp->zw += z_set;
		if (window->map_sz.maxsz_x_p < temp->xm)
			window->map_sz.maxsz_x_p = temp->xm;
		if (window->map_sz.maxsz_x_m > temp->xm)
			window->map_sz.maxsz_x_m = temp->xm;
		if (window->map_sz.maxsz_y_p < temp->ym)
			window->map_sz.maxsz_y_p = temp->ym;
		if (window->map_sz.maxsz_y_m > temp->ym)
			window->map_sz.maxsz_y_m = temp->ym;
		temp = temp->next;
	}
	window->last_zoom_faktor = window->zoom_factor;
	if (window->debug_mode == 1)
		print_stacks(window);
	return (EXIT_SUCCESS);
}

//Point rotateY(Point p, double theta) {
//    Point pRotated;
//    double rad = theta * M_PI / 180.0; // Convert degrees to radians
//    pRotated.x = cos(rad) * p.x + sin(rad) * p.z;
//    pRotated.y = p.y; // Y-coordinate remains unchanged
//    pRotated.z = -sin(rad) * p.x + cos(rad) * p.z;
//    return pRotated;
//}
