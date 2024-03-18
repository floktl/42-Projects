/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:51:31 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/18 13:06:00 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// -----------------------------------------------------------------------------

// main function, user input: ./fdf <map_name>
int	main(int argc, char *argv[])
{
	t_window	window;

	if (argc != 2)
		return (ft_printf("usage: ./fdf <map>.fdf\n"), EXIT_FAILURE);
	if (check_defines() == EXIT_FAILURE
		|| initialize_window_from_args(&window, argv) == EXIT_FAILURE
		|| set_coord(&window) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (initialize_mlx_image(&window) == EXIT_FAILURE)
		return (ft_shutdown_error(window.mlx));
	mlx_resize_hook(window.mlx, ft_resize, &window);
	mlx_scroll_hook(window.mlx, ft_scroll, &window);
	mlx_loop_hook(window.mlx, ft_render, &window);
	mlx_loop(window.mlx);
	mlx_terminate(window.mlx);
	if (window.debug_mode == 1)
		system("leaks fdf");
	return (EXIT_SUCCESS);
}
