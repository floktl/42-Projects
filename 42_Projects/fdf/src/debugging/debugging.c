/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:25:40 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/07 10:59:46 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//	this function are usefool tools for debugging, they are not necessary for
//	the functionality, but they still pass norminette
//

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

int	print_coordinate_data(t_window *window, t_coord *current, const char *color)
{
	printf("%s", color);
	printf("%d|%d\t", current->pos_xm, current->pos_ym);
	printf("Pos map: %f|%f|%f\t", current->xm, current->ym, current->zm);
	printf("len cen: %f\t", current->len_cent);
	printf("zoom: %d\t", window->zoom_factor);
	printf("Pos window: %d|%d|%d\t", current->xw, current->yw,
		current->zw);
	printf("offset map: %f|%f|%f\t", window->map_sz.xm_offset,
		window->map_sz.ym_offset, window->map_sz.zm_offset);
	printf("map pos win: %d|%d|%d\t", window->map_sz.xposmw,
		window->map_sz.yposmw, window->map_sz.zcentmw);
	printf("max sz map: x: %d|%d y: %d|%d\t",
		window->map_sz.maxsz_x_p, window->map_sz.maxsz_x_m,
		window->map_sz.maxsz_y_p, window->map_sz.maxsz_y_m);
	if (current->before_y != NULL)
		printf("by: %d|%d\t", current->before_y->pos_xm,
			current->before_y->pos_ym);
	else
		printf("by;  | \t");
	return (0);
}

//	prints the values of all coordinates (distances, color, degree, position...)
void	print_stacks(t_window *window)
{
	t_coord		*current;
	const char	*color;
	int			row_number;

	if (window->debug_mode == -1)
		return ;
	current = window->coord;
	color = COLOR_RESET;
	row_number = 1;
	while (current != NULL)
	{
		if (current->next != NULL && (current->next->pos_xm - 1) == 1)
			printf("\n");
		if (row_number++ % 2 == 0)
			color = COLOR_MAGENTA;
		else
			color = COLOR_RESET;
		printf("\t");
		print_coordinate_data(window, current, color);
		printf("\n");
		current = current->next;
	}
	printf("%s\n\n", COLOR_RESET);
}

void	print_debug_point(t_window *window)
{
	if (window->debug_mode == -1)
		return ;
	mapmiddle->xw = window->map_sz.maxsz_x_m + window->map_sz.xposmw;
	mapmiddle->yw = window->map_sz.maxsz_y_m + window->map_sz.yposmw;
	mousepos->xw = window->map_sz.maxsz_x_p + window->map_sz.xposmw;
	mousepos->yw = window->map_sz.maxsz_y_p + window->map_sz.yposmw;
	connect_points(window, mapmiddle, mousepos);
}

		//if (current->next != NULL)
		//	printf("nx: %d|%d\t", current->next->pos_xm,
		//		current->next->pos_ym);
		//else
		//	printf("nx:  |  \t");
		//if (current->before != NULL)
		//	printf("bx: %d|%d\t", current->before->pos_xm,
		//		current->before->pos_ym);
		//else
		//	printf("bx:  |  \t");
		//if (current->next_y != NULL)
		//	printf("ny; %d|%d\t", current->next_y->pos_xm,
		//		current->next_y->pos_ym);
		//else
		//	printf("ny:  | \t");
		//printf("wsz: %d|%d", window->width, window->height);

		//printf("color: %d\t", current->color);

		//printf("deg to cen map: %f|%f|%f\t", current->deg_xm,
		//	current->deg_ym, current->deg_zm);