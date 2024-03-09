/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:14:49 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/09 19:44:43 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//-------------- functions to prevent leaks and for cleaning up ----------------
//

//	function for freeing all values within a stack
void	free_stack(t_coord **stack)
{
	t_coord	*head;
	t_coord	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

//	function to reset all pixelsof the window to its default colors
void	clear_image(t_window *window, uint32_t color)
{
	int	x;
	int	y;

	y = 0;
	while (y < window->mlx->height)
	{
		x = 0;
		while (x < window->mlx->width)
		{
			mlx_put_pixel(window->image, x, y, color);
			x++;
		}
		y++;
	}
}
