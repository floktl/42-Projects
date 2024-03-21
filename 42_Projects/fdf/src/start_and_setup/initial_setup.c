/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:28:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/21 11:41:35 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//----------- functions for the standard view of the map on the image ----------
//

//	This function sets the initial window sizes and map sizes
int	initialize_window_from_args(t_window *window, char *argv[])
{
	char	*file_path;
	int		fd;
	char	*line;

	file_path = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		file_path = ft_strjoin("test_maps/", argv[1]);
		if (!file_path)
			return (perror("Error loading maps"), EXIT_FAILURE);
		fd = open(file_path, O_RDONLY);
		free(file_path);
		file_path = NULL;
	}
	if (fd == -1)
		return (close(fd), perror("Error opening file"), EXIT_FAILURE);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), perror("Error reading fdf"), EXIT_FAILURE);
	window->map = read_and_split_lines(fd, line);
	close(fd);
	if (!window->map)
		return (perror("Error reading map"), EXIT_FAILURE);
	if (get_map_size(window) == EXIT_FAILURE
		|| set_default_window_data(window) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

//	assigning all map values to the 3 dimensional array
int	assign_map_values(int ****map, char **collumn, int y)
{
	char	*color;
	int		x;
	int		i;

	x = 0;
	while (collumn[x])
	{
		(*map)[y][x] = malloc(2 * sizeof(int));
		if (!(*map)[y][x])
			return (free_map(*map), EXIT_FAILURE);
		color = ft_strchr(collumn[x], ',');
		i = 0;
		while (collumn[x][i] && collumn[x][i] != ',')
			if (ft_isdigit(collumn[x][i++] - '0') == 1)
				return (perror("non integer in map"), EXIT_FAILURE);
		(*map)[y][x][Z] = ft_atoi(collumn[x]);
		if (color)
			(*map)[y][x][COLOR] = convert_str_to_hex(color);
		else
			(*map)[y][x][COLOR] = Z;
		x++;
	}
	free_two_dimensional_array(collumn);
	(*map)[y][x] = NULL;
	return (EXIT_SUCCESS);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
		return (free(ptr), ptr = NULL, NULL);
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	ptr = NULL;
	return (new_ptr);
}

//	read the fdf file, seperate the values and assign them in an array
int	***read_and_split_lines(int fd, char *line)
{
	int		***map;
	int		count;
	char	**collumn;

	count = 0;
	map = malloc((count + 1) * sizeof(int **));
	if (!map)
		return (NULL);
	ft_printf("\033[0;35mReading map ...\033[0m\n");
	while (line)
	{
		map = ft_realloc(map, (count + 1) * sizeof(int **));
		if (!map)
			return (free_map(map), map = NULL, NULL);
		map[count] = malloc((ft_strlen(line)) * sizeof(int *) * 3);
		if (!map[count])
			return (free_map(map), map = NULL, NULL);
		collumn = ft_split(line, ' ');
		free(line);
		line = NULL;
		if (!collumn || assign_map_values(&map, collumn, count) == EXIT_FAILURE)
			return (free_map(map), map = NULL, NULL);
		line = get_next_line(fd);
		count++;
	}
	return (ft_printf("\033[0;32mSuccesful!\033[0m\n"), map[count] = NULL, map);
}

//	this function assigns all variable values of the map, which will change, but
//	only for all coordinates at once, not every unique coordinate
int	get_map_size(t_window *window)
{
	t_sz		size;
	t_window	*temp;

	size.ym_size = 0;
	temp = window;
	while (temp->map[size.ym_size] != NULL)
		size.ym_size++;
	if (temp->map[0] != NULL)
	{
		size.xm_size = 0;
		while (temp->map[0][size.xm_size] != NULL)
			size.xm_size++;
	}
	if (map_size_default_setting(&window->map_sz, size) == EXIT_FAILURE
		|| find_highest_and_lowest(window) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

//	function to set up the window and image inside the window
int	initialize_mlx_image(t_window *window)
{
	int32_t	max_size_x;
	int32_t	max_size_y;

	ft_printf("\033[0;35mInitializing Window...\033[0m\n");
	window->mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!(window->mlx))
		return (EXIT_FAILURE);
	window->image = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	if (!(window->image)
		|| mlx_image_to_window(window->mlx, window->image, 0, 0) == ERROR)
		return (EXIT_FAILURE);
	mlx_get_monitor_size(0, &max_size_x, &max_size_y);
	mlx_set_window_limit(window->mlx, 300, 300, max_size_x, max_size_y);
	ft_printf("\033[0;34m\nProgramm ready, press I for manual!\033[0m\n");
	return (EXIT_SUCCESS);
}
