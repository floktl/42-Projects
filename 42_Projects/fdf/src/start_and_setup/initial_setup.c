/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:28:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/22 17:52:45 by flo              ###   ########.fr       */
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
	window->map = read_and_split_lines(fd);
	close(fd);
	if (!window->map)
		return (perror("Error reading map"), EXIT_FAILURE);
	if (get_map_size(window) == EXIT_FAILURE
		|| set_default_window_data(window) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// function to read a line from the file and save the values in an array
int	read_line_into_collumn(int fd, int *collumn_counter, char ***collumn)
{
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	if (!line)
		return (-1);
	*collumn = ft_split(line, ' ');
	free(line);
	line = NULL;
	if (!(*collumn))
		return (EXIT_FAILURE);
	*collumn_counter = 0;
	while ((*collumn)[*collumn_counter])
	{
		temp = ft_strtrim((*collumn)[*collumn_counter], " ");
		if (temp)
		{
			free((*collumn)[*collumn_counter]);
			(*collumn)[*collumn_counter] = temp;
			temp = NULL;
		}
		(*collumn_counter)++;
	}
	return (0);
}

//	read the fdf file, seperate the values and assign them in an array
int32_t	***read_and_split_lines(int fd)
{
	int32_t	***map;
	char	**collumn;
	int		row_counter;
	int		collumn_counter;
	int		line;

	row_counter = 0;
	collumn_counter = 0;
	collumn = NULL;
	map = malloc(sizeof(double **));
	if (!map)
		return (NULL);
	ft_printf("\033[0;35mReading map ...\033[0m\n");
	while (1)
	{
		line = read_line_into_collumn(fd, &collumn_counter, &collumn);
		if (line == -1)
		{
			map[row_counter] = NULL;
			break ;
		}
		else if (line == EXIT_FAILURE)
			return (free_map(map), NULL);

		map[row_counter] = malloc(sizeof(double *) * (collumn_counter + 1));
		map[row_counter][collumn_counter] = NULL;
		if (!map[row_counter])
			return (free_map(map), NULL);
		if (assign_map_values(&map[row_counter], collumn) == EXIT_FAILURE)
			return (free_map(map), NULL);
		free_two_dimensional_array(collumn);
		row_counter++;
		map = ft_realloc(map, (row_counter + 1) * sizeof(double **));
		if (!map)
			return (free_map(map), NULL);
	}
	ft_printf("\033[0;32mSuccesful!\033[0m\n");
	return (map);
}

//	assigning all map values to the 3 dimensional array
int	assign_map_values(int32_t ***map_collumn, char **collumn)
{
	char	*color;
	int		x;
	int		i;

	x = 0;
	while (collumn[x] != NULL)
	{
		(*map_collumn)[x] = malloc(2 * sizeof(int));
		if (!(*map_collumn)[x])
			return (EXIT_FAILURE);
		color = ft_strchr(collumn[x], ',');

		i = 0;
		while (collumn[x][i] && collumn[x][i] != ',')
		{
			if (ft_isdigit(collumn[x][i] - '0') == 1)
			{
				ft_printf("Non-integer in map_pos: col: %d\n", x + 1);
				free_two_dimensional_array(collumn);
				return (EXIT_FAILURE);
			}
			i++;
		}
		(*map_collumn)[x][Z] = ft_atoi(collumn[x]);
		if (color)
		{
			(*map_collumn)[x][COLOR] = convert_str_to_hex(color);
		}
		else
			(*map_collumn)[x][COLOR] = Z;
		x++;
	}
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
