/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:32:30 by flo               #+#    #+#             */
/*   Updated: 2024/03/19 11:59:45 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//-------------- functions to calculate the changes when rotating -------------
//

//	function to calculate the points on each rotation axis
void	rotate(double *a, double *b, t_window window, char axis)
{
	double	rad;
	double	new_a;
	double	new_b;
	//double	z_pos_scale = 1.0;
	//double	z_len = window.map_sz.maxsz_z_p;

	if (axis == 'X')
	{
		rad = window.map_sz.xm_rot_deg * (PI / 180.0);
		//if (*b > 0)
		//printf("z_scale: %f", z_pos_scale);
		//else if (*b )
		new_a = ((*a) * ft_cos(rad) - (*b) * ft_sin(rad));
		new_b = ((*a) * ft_sin(rad) + (*b) * ft_cos(rad));
		//new_a *= z_pos_scale;
	}
	if (axis == 'Y')
	{
		rad = window.map_sz.ym_rot_deg * (PI / 180.0);
		new_a = (*b) * ft_cos(rad) - (*a) * ft_sin(rad);
		new_b = (*a) * ft_cos(rad) + (*b) * ft_sin(rad);
	}
	if (axis == 'Z')
	{
		rad = window.map_sz.zm_rot_deg * (PI / 180.0);
		new_a = (*a) * ft_cos(rad) - (*b) * ft_sin(rad);
		new_b = (*a) * ft_sin(rad) + (*b) * ft_cos(rad);
	}
	*a = new_a;
	*b = new_b;
}

//	function to calculate the rotations after a user input
int	rotation_calc(t_window *window, t_coord *cur_point)
{
	double	temp_xm;
	double	temp_ym;
	double	temp_zm;

	temp_xm = cur_point->xm;
	temp_ym = cur_point->ym;
	temp_zm = cur_point->zm;
	rotate(&temp_ym, &temp_zm, *window, 'X');
	rotate(&temp_zm, &temp_xm, *window, 'Y');
	rotate(&temp_xm, &temp_ym, *window, 'Z');
	cur_point->zw = ft_round(temp_zm) + window->map_sz.zm_offset;
	cur_point->xw = ft_round(temp_xm) + window->map_sz.xposmw;
	cur_point->yw = window->map_sz.yposmw - ft_round(temp_ym);
	return (NO_CHANGE);
}
