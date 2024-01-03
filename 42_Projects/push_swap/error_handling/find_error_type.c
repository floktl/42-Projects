/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_error_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:14:38 by fkeitel           #+#    #+#             */
/*   Updated: 2024/01/02 11:58:49 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//
//	handling the error cases:
//

//this function finds the  error type
int	check_error(int n, char *argv[])
{
	if (check_argument_error(n, argv))
		return (-1);
	return (0);
}
