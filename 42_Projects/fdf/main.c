/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:51:31 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/23 12:28:17 by fkeitel          ###   ########.fr       */
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
	print_map(window.map);
	free_map(window.map);
	if (initialize_mlx_image(&window) == EXIT_FAILURE)
		return (ft_shutdown_error(window.mlx));
	mlx_put_string(window.mlx, "Hello World", 10, 10);
	mlx_new_image(window.mlx, window.width, window.height);
	mlx_resize_hook(window.mlx, ft_resize, &window);
	mlx_scroll_hook(window.mlx, ft_scroll, &window);
	mlx_loop_hook(window.mlx, ft_render, &window);
	mlx_loop(window.mlx);
	while (window.coord != NULL)
	{
		t_coord *temp = window.coord;
		window.coord = window.coord->next;
		if (temp)
			free(temp);
		temp = NULL;
	}
	if (window.debug_mode == ON)
		system("leaks fdf");
	mlx_terminate(window.mlx);
	return (EXIT_SUCCESS);
}
