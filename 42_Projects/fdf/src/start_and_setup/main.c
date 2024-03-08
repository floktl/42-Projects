/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:51:31 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/08 09:48:17 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"
#include <dirent.h>

// -----------------------------------------------------------------------------
t_coord *mapmiddle = NULL;
t_coord *mousepos = NULL;

// main function, user input: ./fdf <map_name>
int	main(int argc, char *argv[])
{
	t_window	window;

	mapmiddle = malloc(sizeof(t_coord));
	mousepos = malloc(sizeof(t_coord));
	mapmiddle->zw = 5;
	mousepos->zw = 0;
	if (argc == 2)
	{
		if (initialize_window_from_args(&window, argv) == -1
			|| set_coord(&window) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
		return (ft_printf("usage: ./fdf <map>.fdf\n"), EXIT_FAILURE);
	window.mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!(window.mlx))
		return (ft_shutdown_error(window.mlx));
	window.image = mlx_new_image(window.mlx, WIDTH, HEIGHT);
	if (!(window.image)
		|| mlx_image_to_window(window.mlx, window.image, 0, 0) == -1)
		return (ft_shutdown_error(window.mlx));
	mlx_resize_hook(window.mlx, ft_resize, &window);
	mlx_loop_hook(window.mlx, ft_render, &window);
	mlx_loop(window.mlx);
	free(mapmiddle);
	free(mousepos);
	return (free(window.coord), mlx_terminate(window.mlx), EXIT_SUCCESS);
}
