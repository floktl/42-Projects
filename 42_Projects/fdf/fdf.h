/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:26:16 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/15 08:45:37 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
//--------------------------------- initial setup -----------------------------
//

#ifndef FDF_H
# define FDF_H

//	These are default settings that are not adjustable:
# define ZOOM_DEFAULT 1.0
# define MARGIN 15

//	math data values
# define PI 3.14159265358979323846

//
//-You can change these to adjust different settings, zoom-speed, shift, etc.: -
//

// window size between 100-2500
# define WIDTH 1024
# define HEIGHT 1024
// zoom factor between 0,50-0.99(ZOOM_M) and 1.01-1.50(ZOOM_P)
# define ZOOM_P 1.1
# define ZOOM_M 0.9
// Map movement in x and y direction between 1 and 30
# define SHIFT_DEFAULT 15
//	offset of the map center from the middle point of the window
# define OFFSET_DEFAULT 0.0
// Max zooming faktor end from 1-10(MAX) 11-30(MIN)
# define MAX_MAP_SIZE 35
# define MIN_MAP_SIZE 30
//	color for the z_axis of the map, if not given in the map
# define COLOR_DEFAULT_CEN 0xCFCFFF00
# define COLOR_DEFAULT_PLUS 0xEE550000
# define COLOR_DEFAULT_MIN 0x00DDBB00
# define BRIGHTNESS_DEFAULT 0xCC
//	rotation degree in x, y, z direction
# define DEGREE_DEFAULT 0.0
# define DEGREE_DEFAULT_X 0.0
# define DEGREE_DEFAULT_Y 90.0
# define DEGREE_DEFAULT_Z 0.0
# define ROTATION_SPEED 1.0

// libraries
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdint.h>
# include <limits.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

//
//---------------------structs--------------------------------------------------
//

typedef struct s_rgba_color
{
	int32_t		color_a;
	int32_t		color_b;
	int32_t		r_a;
	int32_t		g_a;
	int32_t		b_a;
	int32_t		a_a;
	int32_t		r_b;
	int32_t		g_b;
	int32_t		b_b;
	int32_t		a_b;
	int32_t		r;
	int32_t		g;
	int32_t		b;
	int32_t		a;
	int32_t		new_color;
}			t_color;

// This struct represents a point in a space (x, y, z)axis
// mid_x/y is the pixel distance to the middle point
// deg_mid_x/y is the degree to the middle point in each axis
// color is the default color of the point
typedef struct s_coordinates
{
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
	int32_t					color;
	struct s_coordinates	*next;
	struct s_coordinates	*before;
	struct s_coordinates	*next_y;
	struct s_coordinates	*before_y;
}	t_coord;

// size of the map, each point is one value
// x = x-axis coordinate , y = y-axis z = z = z-axis
//	m = map object, w = window, cent = center/middlepoint
//
typedef struct s_arr_size
{
	int		xm_size;
	int		ym_size;
	int		maxsz_x_p;
	int		maxsz_x_m;
	int		maxsz_y_p;
	int		maxsz_y_m;
	int		maxsz_z_p;
	int		maxsz_z_m;
	int		xposmw;
	int		yposmw;
	int		zcentmw;
	int		zmcent_plus;
	int		zmcent_minus;
	double	xm_offset;
	double	ym_offset;
	double	zm_offset;
	int		xm_rot_deg;
	int		ym_rot_deg;
	int		zm_rot_deg;
	int		map_area;
}	t_sz;

// settings for the window, map is an array woth the map values, in coord
// are the coordinates for each points, map size with map size values
typedef struct s_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			width;
	int			height;
	void		*win;
	unsigned int			***map;
	t_sz		map_sz;
	t_coord		*coord;
	int			cent_xw;
	int			cent_yw;
	double		zoom;
	int			start_size;
	int			debug_mode;
	int			mouse_posx;
	int			mouse_posy;
	t_coord		debug_point_1;
	t_coord		debug_point_2;
	t_coord		debug_point_3;
	t_coord		debug_point_4;
	float		max_zoom_size;
	float		min_zoom_size;
}	t_window;

//
//---------------------functions------------------------------------------------
//

// setup and initialisations:
int				get_map_size(t_window *map);
unsigned int	***read_and_split_lines(int fd, char *line);
int32_t			set_coord(t_window *window);
int				initialize_window_from_args(t_window *window, char *argv[]);
int				initialize_mlx_image(t_window *window);
// setup help_functions
void		ft_set_before_y(t_coord **head, int iterations, t_window *window);
void		ft_set_after_y(t_coord *head, t_window *window);
int			get_index(t_window *window, int pos_xm, int pos_ym);
void		free_two_dimensional_array(char **param);

//	mathematical functions, as i dont use the math.h library

// mathematics1
void		find_new_point(double x1, double y1, double len_x_to_y, double deg);
float		round_float(float num, int range);
double		ft_sqrt(double a);
//	mathematics2
int			ft_atan(int x);
double		radians(double degrees);
int			ft_round(double num);
int			ft_abs(int num);

// 	main calculations for the map
// algorithm for the calculations:
void		connect_points(t_window *map, t_coord *cur, t_coord *next);
int32_t		find_color(int32_t color_a, int32_t color_b, float t);
int			ft_hook_key(t_window *window, int *x_set, int *y_set);
void		ft_render(void *param);
int32_t		update_coord(t_window *map, int x_set, int y_set);
void		ft_resize(int width, int height, void *param);
// calculations:
int			range_check(t_window *window, int x, int y, int z);
double		ft_sqrt(double a);
float		calc_z(t_coord *cur, t_coord *next, float x_p, float y_p);
double		calc_angle(double a, double b);
int			round_to_int(float num);
int			zoom_calc(t_window *window, t_coord *cur_point);

//clear functions for avoiding memory leaks and trash:
void		free_stack(t_coord **stack);
void		clear_image(t_window *window, uint32_t color);

// additional helper functions
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
int			find_highest_and_lowest(t_window *map);
void		ft_add_back(t_coord **lst, t_coord *new);
int			ft_shutdown_error(mlx_t *mlx);
double		check_zoom_direction(int map_middle, int zoom_position, double zom);

// debugging dunctions:
void		print_stacks(t_window *head);
void		print_debug_point_1(t_window *window);
void		print_debug_point_2(t_window *window);

void		calculate_zoom_pos(t_window *window);
double		check_if_zoomed(t_window *window, int x_set, int y_set);
t_coord		*link_add_pt(t_coord **coord, t_window *window, int x, int y);

int			map_size_default_setting(t_sz *map_sz, t_sz size);
void		update_mapsize(t_sz *map_sz, t_coord *temp);
int			set_default_window_data(t_window *window);
int			assign_degree_len_color(t_window *window, t_coord *coord, int x, int y);
int			assign_coord_position(t_window *window, t_coord *new, int x, int y);
void		ft_scroll(double xoffset, double yoffset, void *param);
int			mouse_shift(t_window *window, int *x_set, int *y_set);
int	mouse_rotation(t_window *window);
int	check_mouse_clicked(t_window *window, int x, int y, enum mouse_key key);

int			shift_map(t_window *window, int *x_set, int *y_set);
double		zoom_map(t_window *window);
int			debug_mode_map(t_window *window);
void		print_debug_point_1(t_window *window);
void		print_debug_point_2(t_window *window);
int			check_defines(void);
int			check_margin_border(t_window *window);
void		connect_points(t_window *window, t_coord *point_a, t_coord *point_b);
int			convert_str_to_hex(char *comma_pos);
void		free_map(unsigned int ***map);
void		print_map(unsigned int ***map);
void	degree(int *rot);

double		rotate_map(t_window *window);
#endif

//void	rotate(double *a, double *b, double angle)
//{
//	double	rad;
//	double	cos_a;
//	double	sin_a;
//	double	new_a;
//	double	new_b;

//	rad = angle * PI / 180.0;
//	cos_a = cos(rad);
//	sin_a = sin(rad);
//	new_a = (*a) * cos_a - (*b) * sin_a;
//	new_b = (*a) * sin_a + (*b) * cos_a;
//	*a = new_a;
//	*b = new_b;
//}

//int	rotation_calc(t_window *window, t_coord *cur_point)
//{
//	double	temp_xm;
//	double	temp_ym;
//	double	temp_zm;

//	temp_xm =
//	temp_ym =
//	temp_zm =
//	rotate(&temp_xm, &temp_ym, window->map_sz.xm_rot_deg);
//	rotate(&temp_ym, &temp_zm, window->map_sz.ym_rot_deg);
//	rotate(&temp_zm, &temp_xm, window->map_sz.zm_rot_deg);
//	cur_point->xw = ft_round(temp_xm) + window->map_sz.xposmw;
//	cur_point->yw = -ft_round(temp_ym) + window->map_sz.yposmw;
//	cur_point->zw = ft_round(temp_zm);
//	return (0);
//}