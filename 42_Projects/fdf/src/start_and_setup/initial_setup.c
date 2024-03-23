/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:28:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/23 23:19:12 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

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
	ft_printf("\033[0;32m\nSuccesful!\033[0m\n");
	if (get_map_size(window) == EXIT_FAILURE
		|| set_default_window_data(window) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	read_line_into_collumn(int fd, int *collumn_counter, char ***collumn)
{
	char		*line;
	char		*temp;
	static int	x_counter = 0;
	char		*trimmed_line;

	line = get_next_line(fd);
	if (!line)
		return (-1);
	trimmed_line = ft_strtrim(line, "\n");
	if (trimmed_line)
	{
		free(line);
		line = trimmed_line;
	}
	*collumn = ft_split(line, ' ');
	free(line);
	line = NULL;
	if (!(*collumn))
		return (EXIT_FAILURE);
	*collumn_counter = 0;
	while ((*collumn)[*collumn_counter])
	{
		temp = ft_strtrim((*collumn)[*collumn_counter], " ");
		free((*collumn)[*collumn_counter]);
		(*collumn)[*collumn_counter] = NULL;
		if (temp)
		{
			(*collumn)[*collumn_counter] = temp;
		}
		(*collumn_counter)++;
	}
	(*collumn)[*collumn_counter] = NULL;
	if (x_counter == 0)
		x_counter = *collumn_counter;
	if (x_counter != *collumn_counter)
		return (INT_MIN);
	return (0);
}

int32_t	***read_and_split_lines(int fd)
{
	int32_t	***map;
	char	**collumn;
	int		row;
	int		collumn_counter;
	int		line;

	row = 0;
	collumn_counter = 0;
	collumn = NULL;
	map = malloc(sizeof(int32_t **));
	if (!map)
		return (NULL);
	ft_printf("\033[0;35m\nReading map ...\033[0m\n");
	while (1)
	{
		map = ft_realloc(map, (row + 1) * sizeof(int32_t **));
		if (!map)
		{
			free_two_dimensional_array(collumn);
			free_map(map);
			return (NULL);
		}
		map[row] = NULL;
		line = read_line_into_collumn(fd, &collumn_counter, &collumn);
		if (line == EXIT_FAILURE || (row == 0 && line == -1)
			|| (collumn_counter == 1) || line == INT_MIN || (row == 0 && line == -1))
		{
			ft_printf("\nMap ERROR!\n");
			if (row == 0 && line == -1)
				ft_printf("map empty\n");
			if (collumn_counter == 1)
				ft_printf("only one point on line %d\n", row + 1);
			if (line == INT_MIN && collumn_counter != 1)
				ft_printf("map must be squared at line: %d\n", row + 1);
			if (row == 0 && line == -1)
				ft_printf("only one row\n");
			map[row] = NULL;
			free_two_dimensional_array(collumn);
			free_map(map);
			return (NULL);
		}
		else if (line == -1)
		{
			break ;
		}
		else if (line == EXIT_FAILURE)
		{
			free_two_dimensional_array(collumn);
			free_map(map);
			return (NULL);
		}
		map[row] = malloc(sizeof(int32_t *) * (collumn_counter + 1));
		if (!map[row])
		{
			free_two_dimensional_array(collumn);
			free_map(map);
			return (NULL);
		}
		map[row][collumn_counter] = NULL;
		if (assign_map_values(&map[row], collumn, row + 1) == EXIT_FAILURE)
		{
			free(map[row]);
			map[row] = NULL;
			free_two_dimensional_array(collumn);
			free_map(map);
			return (NULL);
		}
		free_two_dimensional_array(collumn);
		row++;
	}
	return (map);
}

int	assign_map_values(int32_t ***map_collumn, char **collumn, int line)
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
				x = 0;
				while ((*map_collumn)[x])
				{
					free((*map_collumn)[x]);
					(*map_collumn)[x] = NULL;
					x++;
				}
				ft_printf("Non-integer in line: %d pos: %d\n", line, x);
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
