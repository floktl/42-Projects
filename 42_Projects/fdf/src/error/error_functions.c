/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:54:00 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/18 21:43:11 by flo              ###   ########.fr       */
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
	if (ZOOM_DEFAULT != 1.0 || MARGIN != 15)
		return (ft_printf("Dont change default settings!!\n"), EXIT_FAILURE);
	if (WIDTH < 100 || WIDTH > 2500 || HEIGHT < 100 || HEIGHT > 2500)
		return (ft_printf("Change WIDTH & HEIGHT 100 to 2500\n"), EXIT_FAILURE);
	if (ZOOM_M < 0.5 || ZOOM_M > 0.99 || ZOOM_P < 1.01 || ZOOM_P > 1.50)
		return (ft_printf("zoom 0,5-0.99(M) 1.01-1.5(P)\n"), EXIT_FAILURE);
	if (SHIFT_DEFAULT < 1 || SHIFT_DEFAULT > 30)
		return (ft_printf("SHIFT_DEFAULT between 1 and 30\n"), EXIT_FAILURE);
	if (MAX_MAP_SIZE < 1 || MAX_MAP_SIZE > 50
		|| MIN_MAP_SIZE < 11 || MIN_MAP_SIZE > 30)
		return (ft_printf("mapsizee 1-10(MAX) 11-30(MIN)\n"), EXIT_FAILURE);
	return (NO_CHANGE);
}

//----------------------------- mlx error-cases --------------------------------

//	save shutdown function for the mlx window incase of an error case
int	ft_shutdown_error(mlx_t *mlx)
{
	mlx_close_window(mlx);
	return (perror(mlx_strerror(mlx_errno)), ERROR);
}
