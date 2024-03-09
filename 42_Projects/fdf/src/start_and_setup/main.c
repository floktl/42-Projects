/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:51:31 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/09 21:13:00 by flo              ###   ########.fr       */
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
		if (initialize_window_from_args(&window, argv) == -1
			|| set_coord(&window) == EXIT_FAILURE || check_defines() == -1)
			return (EXIT_FAILURE);
	}
	else
		return (ft_printf("usage: ./fdf <map>.fdf\n"), EXIT_FAILURE);
	if (initialize_mlx_image(&window) == -1)
		return (ft_shutdown_error(window.mlx));
	mlx_resize_hook(window.mlx, ft_resize, &window);
	mlx_scroll_hook(window.mlx, ft_scroll, &window);
	mlx_loop_hook(window.mlx, ft_render, &window);
	mlx_loop(window.mlx);
	return (free(window.coord), mlx_terminate(window.mlx), EXIT_SUCCESS);
}
