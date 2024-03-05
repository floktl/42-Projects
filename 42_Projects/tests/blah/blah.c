/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blah.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:34:50 by fkeitel           #+#    #+#             */
/*   Updated: 2024/02/27 22:00:35 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

typedef struct s_window
{
	double	zoom;
	int		x_mouse_posx;
	int		y_mouse_posy;
}	t_window;

int	zoom_calculations(t_window *window, int *xw, int *yw)
{
	if (window->zoom != 1)
	{
		if (*xw < window->x_mouse_posx && *yw < window->y_mouse_posy)
		{
			*xw -= window->zoom;
			*yw -= window->zoom;
		}
		else if (*xw < window->x_mouse_posx && *yw > window->y_mouse_posy)
		{
			*xw *= window->zoom;
		}
		else if (*xw > window->x_mouse_posx && *yw < window->y_mouse_posy)
		{
			*yw *= window->zoom;
		}
	}
	return (0);
}

int main()
{
	t_window	window = {1.5, 30, 40};
	int			xw = 5;
	int			yw = 15;

	zoom_calculations(&window, &xw, &yw);
	printf("Updated Coordinates: (%d, %d)\n", xw, yw);

	return (0);
}
