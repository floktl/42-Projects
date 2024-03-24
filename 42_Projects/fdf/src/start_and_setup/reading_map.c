/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 09:16:53 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/24 13:25:55 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//------------------------- functions to read the map --------------------------
//

// function to assign the map data to the array and allocate new memory
int32_t	***assign(int32_t ***map, char **collumn, int collumn_counter, int *row)
{
	map[*row] = malloc(sizeof(int32_t *) * (collumn_counter + 1));
	if (!map[*row])
		return (free_map_data(map, collumn, *row));
	map[*row][collumn_counter] = NULL;
	if (assign_map_values(&map[*row], collumn, *row) == EXIT_FAILURE)
	{
		free(map[*row]);
		return (free_map_data(map, collumn, *row));
	}
	(*row)++;
	return (map);
}

//	function to build the three dimensional array and save the map values there
int32_t	***read_map_and_assign_data(int fd)
{
	int32_t	***map;
	char	**collumn;
	int		row;
	int		collumn_counter;
	int		line;

	row = 0;
	collumn_counter = 0;
	map = malloc(sizeof(int32_t **));
	if (!map)
		return (NULL);
	while (1)
	{
		map = ft_realloc(map, (row + 1) * sizeof(int32_t **));
		if (!map)
			return (free_map_data(map, collumn, row));
		map[row] = NULL;
		line = read_line_into_collumn(fd, &collumn_counter, &collumn);
		if (check_for_map_errors(line, row, collumn_counter) == EXIT_FAILURE)
			return (free_map_data(map, collumn, row));
		else if (line == NO_NEW_LINE)
			break ;
		map = assign(map, collumn, collumn_counter, &row);
	}
	return (map);
}

//	function to get a new line with get next line, cut out unecessary data
//	and save the points in a two dimensional array
int	read_line_into_collumn(int fd, int *collumn_counter, char ***collumn)
{
	char		*line;
	static int	x_counter = 0;
	char		*line_without_new_line;

	line = get_next_line(fd);
	if (!line)
		return ((*collumn) = NULL, NO_NEW_LINE);
	line_without_new_line = ft_strtrim(line, "\n");
	if (line_without_new_line)
	{
		free(line);
		line = line_without_new_line;
	}
	*collumn = ft_split(line, ' ');
	free(line);
	line = NULL;
	if (!(*collumn))
		return (EXIT_FAILURE);
	*collumn_counter = 0;
	delete_spaces(collumn_counter, collumn);
	if (x_counter == 0)
		x_counter = *collumn_counter;
	if (x_counter != *collumn_counter)
		return (MAP_NOT_SQUARED);
	return (NEW_LINE);
}

// function to delete spaces from an two dimensional array after using ft_split
void	delete_spaces(int *collumn_counter, char ***collumn)
{
	char		*collumn_without_spaces;

	while ((*collumn)[*collumn_counter])
	{
		collumn_without_spaces = ft_strtrim((*collumn)[*collumn_counter], " ");
		free((*collumn)[*collumn_counter]);
		(*collumn)[*collumn_counter] = NULL;
		if (collumn_without_spaces)
		{
			(*collumn)[*collumn_counter] = collumn_without_spaces;
		}
		(*collumn_counter)++;
	}
	(*collumn)[*collumn_counter] = NULL;
}
