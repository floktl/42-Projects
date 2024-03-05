/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:25:40 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/05 11:05:41 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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

//	prints the values of all coordinates (distances, color, degree, position...)
void	print_stacks(t_window *window)
{
	t_coord		*current;
	int			row;
	int			new_row;
	const char	*color;

	if (window == NULL)
	{
		ft_printf("The list is empty.\n");
		return ;
	}
	row = 1;
	current = window->coord;
	new_row = current->pos_ym;
	while (current != NULL)
	{
		if (row % 2 == 0)
			color = COLOR_MAGENTA;
		else
			color = COLOR_RESET;
		if ((current->pos_ym - 1) >= new_row)
		{
			new_row = current->pos_ym;
			ft_printf("\n");
		}
		ft_printf("\t");
		ft_printf("%s", color);
		ft_printf("%d|%d\t", current->pos_xm, current->pos_ym);
		//if (current->next != NULL)
		//	ft_printf("nx: %d|%d\t", current->next->pos_xm,
		//		current->next->pos_ym);
		//else
		//	ft_printf("nx:  |  \t");
		//if (current->before != NULL)
		//	ft_printf("bx: %d|%d\t", current->before->pos_xm,
		//		current->before->pos_ym);
		//else
		//	ft_printf("bx:  |  \t");
		//if (current->next_y != NULL)
		//	ft_printf("ny; %d|%d\t", current->next_y->pos_xm,
		//		current->next_y->pos_ym);
		//else
		//	ft_printf("ny:  | \t");
		//if (current->before_y != NULL)
		//	ft_printf("by: %d|%d\t", current->before_y->pos_xm,
		//		current->before_y->pos_ym);
		//else
		//	ft_printf("by;  | \t");
		ft_printf("Pos map: %d|%d|%d\t", current->xm, current->ym, current->zm);
		ft_printf("len cen: %d\t", current->len_cent);
		//printf("deg to cen map: %f|%f|%f\t", current->deg_xm,
		//	current->deg_ym, current->deg_zm);
		ft_printf("zoom: %d\t", window->zoom_factor);
		//ft_printf("color: %d\t", current->color);
		ft_printf("Pos window: %d|%d|%d\t", current->xw, current->yw,
			current->zw);
		ft_printf("offset map: %d|%d|%d\t", window->map_sz.xm_offset,
			window->map_sz.ym_offset, window->map_sz.zm_offset);
		ft_printf("map pos win: %d|%d|%d\t", window->map_sz.xposmw,
			window->map_sz.yposmw, window->map_sz.zcentmw);
		ft_printf("max sz map: x: %d|%d y: %d|%d\t",
			window->map_sz.maxsz_x_p, window->map_sz.maxsz_x_m,
			window->map_sz.maxsz_y_p, window->map_sz.maxsz_y_m);
		//ft_printf("wsz: %d|%d", window->width, window->height);
		ft_printf("\n");
		row++;
		current = current->next;
	}
	ft_printf("%s", COLOR_RESET);
	ft_printf("\n\n");
}
