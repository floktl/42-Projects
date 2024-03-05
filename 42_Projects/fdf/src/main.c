/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:51:31 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/05 22:32:24 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <dirent.h>

// -----------------------------------------------------------------------------

int	initialize_window_from_args(t_window *window, char *argv[])
{
	char	*file_path;
	int		fd;

	file_path = ft_strjoin("test_maps/", argv[1]);
	fd = open(file_path, O_RDONLY);
	free(file_path);
	if (fd == -1)
		return (perror("Error opening file"), -1);
	window->map = read_and_split_lines(fd);
	close(fd);
	get_array_size(window);
	window->start_size = (WIDTH / (window->map_sz.xm_size + 2));
	window->zoom_factor = window->start_size;
	window->last_zoom_faktor = window->zoom_factor;
	window->cent_xw = WIDTH / 2;
	window->cent_yw = HEIGHT / 2;
	window->mouse_posx = window->cent_xw;
	window->mouse_posy = window->cent_yw;
	window->map_sz.xm_offset = 0.0;
	window->map_sz.ym_offset = 0.0;
	window->map_sz.zm_offset = 0.0;
	window->debug_mode = -1;
	window->width = WIDTH;
	window->height = HEIGHT;
	return (0);
}

int32_t	update_coord_size(t_window *window, int x_set, int y_set)
{
	t_coord		*temp;

	temp = window->coord;
	while (temp != NULL)
	{
		temp->xw = temp->xm + x_set;
		temp->yw = -temp->ym + y_set;
		temp = temp->next;
	}
	return (EXIT_SUCCESS);
}

void	ft_resize(int width, int height, void *param)
{
	t_window	*window;

	window = (t_window *)param;
	clear_image(window, 0x00000000);
	if (width > window->width || height > window->height)
		mlx_resize_image(window->image, width, height);
	window->width = width;
	window->height = height;
	window->cent_xw = width / 2;
	window->cent_yw = height / 2;
    window->map_sz.xm_offset = window->cent_xw - window->map_sz.xposmw;
    window->map_sz.ym_offset = window->cent_yw - window->map_sz.yposmw;
	window->mouse_posx = window->cent_xw;
	window->mouse_posy = window->cent_yw;
	print_stacks(window);
}

// main function, user input: ./fdf <map_name>
int	main(int argc, char *argv[])
{
	t_window	window;

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
	free(window.coord);
	//system("leaks fdf");
	mlx_terminate(window.mlx);
	return (EXIT_SUCCESS);
}

//window->cent_yw + window->zoom_factor / 2
