/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:54:00 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/09 19:48:06 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//---------------------- functions to hadle error cases ------------------------
//

//--------------------------- program error-cases ------------------------------

//	function to check if the defines are out of the allowed border
int	check_defines(void)
{
	if (ZOOM_DEFAULT != 1.0 || MAX_LINES != 1024 || MARGIN != 15)
		return (printf("Dont change the default settings!!\n"), -1);
	if (WIDTH < 100 || WIDTH > 2500 || HEIGHT < 100 || HEIGHT > 2500)
		return (printf("Change WIDTH & HEIGHT to between 100 and 2500\n"), -1);
	if (ZOOM_M < 0.5 || ZOOM_M > 0.99 || ZOOM_P < 1.01 || ZOOM_P > 1.50)
		return (printf("zoom factor 0,50-0.99(M) and 1.01-1.50(P)\n"), -1);
	if (SHIFT_DEFAULT < 1 || SHIFT_DEFAULT > 30)
		return (printf("SHIFT_DEFAULT between 1 and 30\n"), -1);
	if (MAX_MAP_SIZE < 1 || MAX_MAP_SIZE > 10
		|| MIN_MAP_SIZE < 11 || MIN_MAP_SIZE > 30)
		return (printf("zoom faktor from 1-10(MAX) 11-30(MIN)\n"), -1);
	return (0);
}

//----------------------------- mlx error-cases --------------------------------

//	save shutdown function for the mlx window incase of an error case
int	ft_shutdown_error(mlx_t *mlx)
{
	mlx_close_window(mlx);
	return (puts(mlx_strerror(mlx_errno)), -1);
}
