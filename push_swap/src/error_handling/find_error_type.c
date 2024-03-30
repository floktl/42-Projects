/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_error_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:14:38 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/26 08:50:41 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//
//	handling the error cases:
//

//this function finds the  error type
int	check_error(char **args)
{
	if (check_argument_error(args))
		return (-1);
	return (0);
}
