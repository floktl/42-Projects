/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_error_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:14:38 by fkeitel           #+#    #+#             */
/*   Updated: 2023/11/27 18:56:50 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//
//	handling the error cases:
//

//this function finds the  error type
int	check_error(int n, char *argv[], t_stack **stack_a, t_stack **stack_b)
{
	if (check_argument_error(n, argv) || \
		check_stack_errors(stack_a, stack_b))
		return (1);
	return (0);
}
