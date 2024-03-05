/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:26:16 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/05 16:45:16 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//---------------------initial setup--------------------------------------------
#ifndef FDF_H
# define FDF_H
# define WIDTH 1024
# define HEIGHT 1024
# define MAX_LINES 1024
# define MARGIN 5

// libraries
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <limits.h>
// window size

//
//---------------------structs--------------------------------------------------
//

// represents a point in a space (x, y, z)axis
// mid_x/y is the pixel distance to the middle point
// deg_mid_x/y is the degree to the middle point in each axis
// zoom is the zoom multiplactor to zoom the picture
// color is the setted color of the point
typedef struct s_coordinates {
	int						pos_xm;
	int						pos_ym;
	int						xw;
	int						yw;
	int						zw;
	double					xm;
	double					ym;
	double					zm;
	double					len_cent;
	double					deg_xm;
	double					deg_ym;
	double					deg_zm;
	uint32_t				color;
	struct s_coordinates	*next;
	struct s_coordinates	*before;
	struct s_coordinates	*next_y;
	struct s_coordinates	*before_y;
}	t_coord;

// size of the map, each point is one value
// x = x-axis coordinate , y = y-axis z = z = z-axis
//	m = map object, w = window, cent = center/middlepoint
//
typedef struct s_arr_size {
	int	xm_size;
	int	ym_size;
	int	maxsz_x_p;
	int	maxsz_x_m;
	int	maxsz_y_p;
	int	maxsz_y_m;
	int	xposmw;
	int	yposmw;
	int	zcentmw;
	int	zmcent_plus;
	int	zmcent_minus;
	int	xm_offset;
	int	ym_offset;
	int	zm_offset;
	int	xm_rot_deg;
	int	ym_rot_deg;
	int	zm_rot_deg;
}	t_sz;

// settings for the window, map is an array woth the map values, in coord
// are the coordinates for each points, map size with map size values

typedef struct s_window {
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			width;
	int			height;
	void		*win;
	char		***map;
	t_sz		map_sz;
	t_coord		*coord;
	int			cent_xw;
	int			cent_yw;
	int			zoom_factor;
	int			last_zoom_faktor;
	int			start_size;
	int			debug_mode;
	int			mouse_posx;
	int			mouse_posy;
}	t_window;

//
//---------------------functions------------------------------------------------
//

// setup and initialisations:
void		get_array_size(t_window *map);
char		***read_and_split_lines(int fd);
int32_t		set_coord(t_window *window);
// setup help_functions
void		ft_set_before_y(t_coord **head, int iterations, t_window *window);
void		ft_set_after_y(t_coord *head, t_window *window);
int			get_index(t_window *window, int pos_xm, int pos_ym);

//	mathematical functions, as i dont use the math.h library

// mathematics1
void		find_new_point(double x1, double y1, double len_x_to_y, double deg);
float		round_float(float num, int range);
double		ft_sqrt(double a);
//	mathematics2
int			atan_approximation(int x);
double		radians(double degrees);

// 	main calculations for the map
// algorithm for the calculations:
void		connect_points(t_window *map, t_coord *cur, t_coord *next);
int			ft_hook_key(t_window *window, int *x_set, int *y_set, int *z_set);
void		ft_render(void *param);
int32_t		update_coord(t_window *map, int x_set, int y_set, int z_set);
void		ft_resize(int width, int height, void *param);
// calculations:
int			range_check(t_window *window, int x, int y, int z);
double		ft_sqrt(double a);
float		calc_z(t_coord *cur, t_coord *next, float x_p, float y_p);
double		calc_angle(double a, double b, char which_side);
int			round_to_int(float num);
int			zoom_calc(t_window *window, t_coord *cur_point, double zoom);

//clear functions for avoiding memory leaks and trash:
void		free_stack(t_coord **stack);
void		clear_image(t_window *window, uint32_t color);

// additional helper functions
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		find_highest_and_lowest(t_window *map);
void		ft_add_back(t_coord **lst, t_coord *new);
int			ft_shutdown_error(mlx_t *mlx);

// debugging dunctions:
void		print_stacks(t_window *head);

#endif
