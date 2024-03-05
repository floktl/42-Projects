/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blah.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:34:50 by fkeitel           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/02/27 22:00:35 by flo              ###   ########.fr       */
=======
/*   Updated: 2024/02/27 13:39:28 by fkeitel          ###   ########.fr       */
>>>>>>> 6f7813eb9abf78c4fe7aa3b0219dfe528de5c02f
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
<<<<<<< HEAD
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

=======
#include <math.h>

int round_to_int(float num) {
    if (num >= 0) {
        return (int)(num + 0.5);
    } else {
        return (int)(num - 0.5);
    }
}

int	main(void)
{
	printf("%d", round_to_int(3.654));
>>>>>>> 6f7813eb9abf78c4fe7aa3b0219dfe528de5c02f
	return (0);
}
