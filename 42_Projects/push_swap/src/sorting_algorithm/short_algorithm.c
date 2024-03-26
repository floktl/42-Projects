/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:53:26 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/25 21:48:55 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//algorithm if stack a has 3 nodes
void	algorithm_three_nodes(t_list **stack_a, int highest, int lowest)
{
	if (highest == 3)
	{
		if (lowest == 1)
			return ;
		swap_a(stack_a);
	}
	else if (highest == 2)
	{
		if (lowest == 1)
		{
			swap_a(stack_a);
			rotate_a(stack_a);
		}
		else
			reverse_rotate_a(stack_a);
	}
	else if (highest == 1)
	{
		rotate_a(stack_a);
		if (lowest == 3)
			swap_a(stack_a);
	}
}

//algorithm if stack b has less or equal than five nodes
int	short_algorithm(t_list **stack_a, int nodes_count)
{
	int		highest;
	int		lowest;
	t_list	*temp_a;

	temp_a = *stack_a;
	highest = find_position(find_highest(temp_a), temp_a);
	lowest = find_position(find_lowest(temp_a), temp_a);
	if (nodes_count == 0)
		return (-1);
	if (nodes_count == 1)
		return (0);
	else if (nodes_count == 2 && highest != 2)
		swap_a(stack_a);
	else if (nodes_count == 3)
		algorithm_three_nodes(stack_a, highest, lowest);
	return (0);
}
