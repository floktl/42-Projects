/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:28:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/11 09:52:24 by fkeitel          ###   ########.fr       */
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

	file_path = ft_strjoin("test_maps/", argv[1]);
	if (!file_path)
		return (perror("Error loading maps"), -1);
	fd = open(file_path, O_RDONLY);
	//free(file_path);
	if (fd == -1)
		return (perror("Error opening file"), -1);
	window->map = read_and_split_lines(fd);
	if (!window->map)
		return (EXIT_FAILURE);
	//get_map_size(window);
	//set_default_window_data(window);
	return (0);
}

//	the name explain itself, this function reads the map data from the fdf file,
//	and handles errors, returns the map
int	***read_and_split_lines(int fd)
{
	int		***map;
	char	*line;
	int		count;
	char	**collumn;
	char	*comma_pos;
	int		j;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		int ***newMap = realloc(map, (count + 2) * sizeof(int **));
		map = newMap;
		map[count] = malloc((ft_strlen(line) + 1) * sizeof(int *));
		collumn = ft_split(line, ' ');
		free(line);
		j = 0;
		while (collumn[j])
		{
			map[count][j] = malloc(3 * sizeof(int *));
			comma_pos = strchr(collumn[j], ',');
			if (comma_pos)
			{
				*comma_pos = '\0';
				map[count][j][0] = atoi(collumn[j]);
				printf("%d\n", map[count][j][0]);
				if (!map[count][j][0])
					printf("error");
				sscanf(comma_pos + 1, "%x", &map[count][j][1] + 0xFF);
			}
			else
			{
				map[count][j][0] = atoi(collumn[j]);
					printf("%d\n", map[count][j][0]);
				if (!map[count][j][0])
					printf("error2");
				map[count][j][1] = 0;
			}
			map[count][j][2] = INT_MAX;
			j++;
		}
		map[count][j] = NULL;
		collumn = NULL;
		line = get_next_line(fd);
		count++;
	}
	map[count] = NULL;
	close(fd);
	return (map);
}

//	this function assigns all variable values of the map, which will change, but
//	only for all coordinates at once, not every unique coordinate
void	get_map_size(t_window *window)
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
}

//	function to set up the window and image inside the window
int	initialize_mlx_image(t_window *window)
{
	window->mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!(window->mlx))
		return (-1);
	window->image = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	if (!(window->image)
		|| mlx_image_to_window(window->mlx, window->image, 0, 0) == -1)
		return (-1);
	return (0);
}


















//int	***read_and_split_lines(int fd)
//{
//	int		***map;
//	char	*line;
//	int		count;
//	char	**collumn;
//	char	*comma_pos;
//	int		j;

//	count = 0;
//	map = malloc((MAX_LINES + 1) * sizeof(int **));
//	if (!map)
//		return (perror("Failed to allocate memory for rows"), NULL);
//	line = get_next_line(fd);
//	while (line)
//	{
//		map[count] = malloc((MAX_COLUMNS + 1) * sizeof(int *));
//		if (!map[count])
//			return (perror("Failed to allocate memory for columns"), NULL);
//		collumn = ft_split(line, ' ');
//		free(line);
//		if (!collumn)
//		{
//			while (--count >= 0)
//			{
//				free(map[count]);
//				map[count] = NULL;
//			}
//			return (free(map), map = NULL, NULL);
//		}
//		j = 0;
//		while (collumn[j])
//		{
//			map[count][j] = malloc(3 * sizeof(int *));
//			if (!map[count][j])
//			{
//				perror("Failed to allocate memory for values");
//				free(collumn);
//				while (--j >= 0)
//					free(map[count][j]);
//				free(map[count]);
//				map[count] == NULL;
//				while (--count >= 0)
//				{
//					while (--j >= 0)
//						free(map[count][j]);
//					free(map[count]);
//				}
//				return (free(map), NULL);
//			}
//			comma_pos = strchr(collumn[j], ',');
//			if (comma_pos)
//			{
//				*comma_pos = '\0';
//				map[count][j][0] = atoi(collumn[j]);
//				sscanf(comma_pos + 1, "%x", &map[count][j][1] + 0xFF);
//			}
//			else
//			{
//				map[count][j][0] = atoi(collumn[j]);
//				map[count][j][1] = 0;
//			}
//			map[count][j][2] = INT_MAX;
//			j++;
//		}
//		map[count][j] = NULL;
//		free(collumn);
//		if (count++ < MAX_LINES)
//		{
//			line = get_next_line(fd);
//			if (!line)
//			{
//				free(line);
//				line = NULL;
//			}
//		}
//		else
//			break ;
//	}
//	map[count] = NULL;
//	close(fd);
//	return (map);
//}