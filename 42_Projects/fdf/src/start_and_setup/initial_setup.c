/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:28:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/14 07:20:53 by fkeitel          ###   ########.fr       */
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

	file_path = ft_strjoin("test_maps/", argv[1]);
	if (!file_path)
		return (perror("Error loading maps"), EXIT_FAILURE);
	fd = open(file_path, O_RDONLY);
	free(file_path);
	if (fd == -1)
		return (perror("Error opening file"), EXIT_FAILURE);
	line = get_next_line(fd);
	if (!line)
		return (perror("Error reading fdf"), EXIT_FAILURE);
	window->map = read_and_split_lines(fd, line);
	if (!window->map)
		return (perror("Error reading map"), EXIT_FAILURE);
	close(fd);
	if (get_map_size(window) == EXIT_FAILURE
		|| set_default_window_data(window) == EXIT_FAILURE)
		return (perror("Error data"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

//	assigning all map values to the 3 dimensional array
int	assign_map_values(unsigned int ****map, char **collumn, int count)
{
	char	*comma_pos;
	int		j;

	j = 0;
	while (collumn[j])
	{
		(*map)[count][j] = malloc(2 * sizeof(unsigned int));
		comma_pos = ft_strchr(collumn[j], ',');
		(*map)[count][j][0] = ft_atoi(collumn[j]);
		if (comma_pos)
		{
			*comma_pos = '\0';
			(*map)[count][j][1] = convert_str_to_hex(comma_pos);
		}
		else
			(*map)[count][j][1] = 0;
		j++;
	}
	free_two_dimensional_array(collumn);
	(*map)[count][j] = NULL;
	return (EXIT_SUCCESS);
}

//	read the fdf file, seperate the values and assign them in an array
unsigned int	***read_and_split_lines(int fd, char *line)
{
	unsigned int	***map;
	int				count;
	char			**collumn;

	count = 0;
	map = malloc((count + 1) * sizeof(unsigned int **));
	if (!map)
		return (NULL);
	ft_printf("Reading map...\n");
	while (line)
	{
		map = realloc(map, (count + 1) * sizeof(unsigned int **));
		if (!map)
			return (free_map(map), NULL);
		map[count] = malloc((ft_strlen(line) + 1) * sizeof(unsigned int *));
		if (!map[count])
			return (free_map(map), NULL);
		collumn = ft_split(line, ' ');
		free(line);
		if (!collumn || assign_map_values(&map, collumn, count) == EXIT_FAILURE)
			return (free_map(map), NULL);
		line = get_next_line(fd);
		count++;
	}
	return (map[count] = NULL, map);
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
	map_size_default_setting(&window->map_sz, size);
	find_highest_and_lowest(window);
	return (EXIT_SUCCESS);
}

//	function to set up the window and image inside the window
int	initialize_mlx_image(t_window *window)
{
	window->mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!(window->mlx))
		return (EXIT_FAILURE);
	window->image = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	if (!(window->image)
		|| mlx_image_to_window(window->mlx, window->image, 0, 0) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
