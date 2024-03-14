/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:51:31 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/14 07:20:42 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// -----------------------------------------------------------------------------

// main function, user input: ./fdf <map_name>
int	main(int argc, char *argv[])
{
	t_window	window;

	if (argc == 2)
	{
		if (check_defines() == EXIT_FAILURE
			|| initialize_window_from_args(&window, argv) == EXIT_FAILURE
			|| set_coord(&window) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		free_map(window.map);
	}
	else
		return (ft_printf("usage: ./fdf <map>.fdf\n"), EXIT_FAILURE);
	ft_printf("Initilazing window...\n");
	if (initialize_mlx_image(&window) == EXIT_FAILURE)
		return (ft_shutdown_error(window.mlx));
	ft_printf("Programm ready, press I for manual!\n");
	mlx_resize_hook(window.mlx, ft_resize, &window);
	mlx_scroll_hook(window.mlx, ft_scroll, &window);
	mlx_loop_hook(window.mlx, ft_render, &window);
	mlx_loop(window.mlx);
	mlx_terminate(window.mlx);
	system("leaks fdf");
	return (EXIT_SUCCESS);
}
