/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:28:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/24 11:45:18 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//--------- function to initialize the coordinate data from the map ------------
//

//	function to read the map from the argument and process the data
int	initialize_window_from_args(t_window *window, char *argv[])
{
	char	*file_path;
	int		fd;

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
	ft_printf("\033[0;35m\nReading map ...\033[0m\n");
	window->map = read_map_and_assign_data(fd);
	if (close(fd) && !window->map)
		return (perror("Error reading map"), EXIT_FAILURE);
	ft_printf("\033[0;32m\nSuccesful!\033[0m\n");
	if (get_map_size(window) == EXIT_FAILURE
		|| set_default_window_data(window) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

//	function to assign the coordinate data from the map into 3-dimensional array
int	assign_map_values(int32_t ***map_x_axis, char **collumn, int line)
{
	char	*color;
	int		x;

	x = 0;
	while (collumn[x] != NULL)
	{
		(*map_x_axis)[x] = malloc(2 * sizeof(int));
		if (!(*map_x_axis)[x])
			return (EXIT_FAILURE);
		color = ft_strchr(collumn[x], ',');
		if (check_map_integer(map_x_axis, collumn, &x, line) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		(*map_x_axis)[x][Z] = ft_atoi(collumn[x]);
		if (color)
		{
			(*map_x_axis)[x][COLOR] = convert_str_to_hex(color);
		}
		else
			(*map_x_axis)[x][COLOR] = Z;
		x++;
	}
	free_two_dimensional_array(collumn);
	return (EXIT_SUCCESS);
}

//	this function assigns all variable values of the map, which will change, but
//	only for the whole map at once, not every unique coordinate
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
