/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:28:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/09 20:58:27 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//----------- functions for the standard view of the map on the image ----------
//

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

//	This function sets the initial window sizes and map sizes
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
	get_map_size(window);
	set_default_window_data(window);
	return (0);
}

//	the name explain itself, this function reads the map data from the fdf file,
//	and handles errors, returns the map
char	***read_and_split_lines(int fd)
{
	char	***lines_tokens;
	char	*line;
	int		count;

	count = 0;
	lines_tokens = malloc((MAX_LINES + 1) * sizeof(char **));
	if (!lines_tokens)
		return (perror("Failed to allocate memory for line tokens"), NULL);
	line = get_next_line(fd);
	while ((line))
	{
		lines_tokens[count] = ft_split(line, ' ');
		free(line);
		if (!lines_tokens[count])
		{
			while (--count >= 0)
				free(lines_tokens[count]);
			return (free(lines_tokens), NULL);
		}
		if (count++ < MAX_LINES)
			line = get_next_line(fd);
		else
			break ;
	}
	return (close(fd), lines_tokens);
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
