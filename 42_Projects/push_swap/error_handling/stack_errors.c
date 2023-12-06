/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:49:46 by fkeitel           #+#    #+#             */
/*   Updated: 2023/11/27 18:56:59 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//
//	errors with the two stacks:
//

//check for errors in the stacks
int	check_stack_errors(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	if (!(*stack_a) || !(*stack_b))
		i = 1;
	return (0);
}
