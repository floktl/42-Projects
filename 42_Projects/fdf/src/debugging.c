/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:25:40 by fkeitel           #+#    #+#             */
/*   Updated: 2024/02/29 11:57:00 by fkeitel          ###   ########.fr       */
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

int	print_names_from_stack(int width)
{
	printf("%s", COLOR_CYAN);
	if (printf("\n  %-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%s\n",
			width, "Row",
			width, "xm",
			width, "ym",
			width, "xn",
			width, "xb",
			width, "yn",
			width, "yb",
			width, "zw",
			width, "yw",
			width, "zw",
			width, "xcentm",
			width, "ycentm",
			width, "zcentm",
			width, "xm_xmcent",
			width, "ym_ymcent",
			width, "zm_zmcent",
			width, "len_cent",
			width, "°x",
			width, "°y",
			width, "°z",
			width, "zoom",
			width, "color",
			width, "xm_offet",
			width, "ym_offet",
			width, "zm_offet",
			COLOR_RESET)
		== 0)
		return (0);
	else
		return (-1);
}

void	print_stacks(t_window *head)
{
	t_coord		*current;
	int			width;
	int			row;
	int			new_row;
	const char	*color;

	if (head == NULL)
	{
		ft_printf("The list is empty.\n");
		return ;
	}
	width = 10;
	row = 1;
	current = head->coord;
	new_row = current->pos_ym;
	print_names_from_stack(width);
	while (current != NULL)
	{
		if (row % 2 == 0)
			color = COLOR_MAGENTA;
		else
			color = COLOR_RESET;
		if ((current->pos_ym - 1) >= new_row)
		{
			print_names_from_stack(width);
			new_row = current->pos_ym;
		}
		printf("  ");
		printf("%s", color);
		printf("%-*d", width, row);
		printf("%-*d", width, current->pos_xm);
		printf("%-*d", width, current->pos_ym);
		if (current->next != NULL)
			printf("%-*d", width, current->next->pos_xm);
		else
			printf("%-*d", width, 0);
		if (current->before != NULL)
			printf("%-*d", width, current->before->pos_xm);
		else
			printf("%-*d", width, 0);
		if (current->next != NULL)
			printf("%-*d", width, current->next->pos_ym);
		else
			printf("%-*d", width, 0);
		if (current->before_y != NULL)
			printf("%-*d", width, current->before_y->pos_ym);
		else
			printf("%-*d", width, 0);
		printf("%-*d", width, current->xw);
		printf("%-*d", width, current->yw);
		printf("%-*d", width, current->zw);
		printf("%-*d", width, head->map_sz.xcentm);
		printf("%-*d", width, head->map_sz.ycentm);
		printf("%-*d", width, head->map_sz.zcentm);
		printf("%-*d", width, current->xm_xmcent);
		printf("%-*d", width, current->ym_ymcent);
		printf("%-*d", width, current->zm_zmcent);
		printf("%-*d", width, current->len_cent);
       	printf("%-*.*f", width, 3, current->deg_cmx_xm);
        printf("%-*.*f", width, 3, current->deg_cmy_ym);
        printf("%-*.*f", width, 3, current->deg_cmz_zm);
		printf("%-*d", width, head->zoom_factor);
		printf("%-*X", width, current->color);
		printf("%-*d", width, head->map_sz.xm_offset);
		printf("%-*d", width, head->map_sz.ym_offset);
		printf("%-*d", width, head->map_sz.zm_offset);
		printf("\n");
		row++;
		current = current->next;
	}
	printf("%s", COLOR_RESET);
	printf("\n\n");
}
