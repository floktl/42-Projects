/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:51:31 by fkeitel           #+#    #+#             */
/*   Updated: 2024/02/29 11:46:25 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <dirent.h>

// -----------------------------------------------------------------------------

void	list_mapnames(void)
{
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir("test_maps/");
	if (dir == NULL)
	{
		perror("opendir");
		return ;
	}
	printf("aviable maps");
	entry = readdir(dir);
	while (entry)
	{
		if (entry->d_type == DT_REG)
			printf("%s\n", entry->d_name);
		entry = readdir(dir);
	}
	closedir(dir);
}

// main function, user input: ./fdf <map_name>
int32_t	main(int argc, char *argv[])
{
	t_window	window;
	int			fd;
	char		*file_path;

	if (argc == 2 )
	{
		file_path = ft_strjoin("test_maps/", argv[1]);
		fd = open(file_path, O_RDONLY);
		free(file_path);
		if (fd == -1)
			return (perror("Error opening file"), -1);
		window.map = read_and_split_lines(fd);
		close(fd);
		get_array_size(&window);
		window.start_size = 50;
		window.zoom_factor = window.start_size;
		window.last_zoom_faktor = window.zoom_factor;
		window.cent_xw = WIDTH / 2;
		window.cent_yw = HEIGHT / 2;
		window.mouse_posx = window.cent_xw;
		window.mouse_posy = window.cent_yw;
		window.map_sz.xm_offset = window.cent_xw + window.zoom_factor / 2;
		window.map_sz.ym_offset = window.cent_yw + window.zoom_factor / 2;
		window.map_sz.zm_offset = 0;
		window.debug_mode = -1;
		set_coord(&window);
	}
	else
		return (ft_printf("type for example: ./fdf 42.fdf\naviable maps: \n"),
			list_mapnames(), -1);
	window.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!(window.mlx))
		return (ft_shutdown_error(window.mlx));
	window.image = mlx_new_image(window.mlx, WIDTH, HEIGHT);
	if (!(window.image)
		|| mlx_image_to_window(window.mlx, window.image, 0, 0) == -1)
		return (ft_shutdown_error(window.mlx));
	//mlx_loop_hook(window.mlx, ft_render, &window);
	mlx_loop(window.mlx);
	free(window.coord);
	//system("leaks fdf");
	return (mlx_terminate(window.mlx), EXIT_SUCCESS);
}
