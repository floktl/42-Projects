/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:26:16 by fkeitel           #+#    #+#             */
/*   Updated: 2024/02/29 10:29:37 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//---------------------initial setup--------------------------------------------
#ifndef FDF_H
# define FDF_H
# define WIDTH 1024
# define HEIGHT 1024
# define MAX_LINES 1024

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
	int						xcentm;
	int						ycentm;
	int						zcentm;
	int						xm_xmcent;
	int						ym_ymcent;
	int						zm_zmcent;
	int						len_cent;
	float					deg_cmx_xm;
	float					deg_cmy_ym;
	float					deg_cmz_zm;
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
	int	xcentm;
	int	ycentm;
	int	zcentm;
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
t_window	*set_coord(t_window *map);
// algorithm for the calculations:
void		connect_points(t_window *map, t_coord *cur, t_coord *next);
int			ft_hook(t_window *map);
void		ft_render(void *param);
int32_t		update_coord(t_window *map, int x_set, int y_set, int z_set);
// calculations:
int			range_check(t_window *window, int *x, int *y, int *z);
double		ft_sqrt(double a);
float		calc_z(t_coord *cur, t_coord *next, float x_p, float y_p);
float		calc_angle(int a, int b, char which_side);
int			round_to_int(float num);
int			zoom_calc(t_window *window, t_coord *cur_point);

//clear functions for avoiding memory leaks and trash:
void		free_stack(t_coord **stack);
void		clear_image(mlx_image_t *image, uint32_t color);
// additional helper functions
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		find_highest_and_lowest(t_window *map);
void		ft_add_back(t_coord **lst, t_coord *new);
int			ft_shutdown_error(mlx_t *mlx);
// debugging dunctions:
int			print_names_from_stack(int width);
void		print_stacks(t_window *head);

#endif