/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:48:05 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/19 12:07:40 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//
//	algorithms for sorting the stack_a, the smallest number on the top:
//

//calculate the minumum operations necessary to push the best num
//from stack_a to stack_b
int	opration_calculations(t_stack *a, t_stack *b, int *cur_a, int *cur_b)
{
	t_stack	*tmp;
	int		best;
	int		best_num;
	int		*highest;

	best_num = INT_MAX;
	tmp = a;
	highest = find_three_highest(tmp);
	while (tmp != NULL)
	{
		if (tmp->content != highest[0] && tmp->content != highest[1] \
			&& tmp->content != highest[2])
		{
			*cur_b = calculate_op(a, b, ins_pos(b, tmp->content));
			*cur_a = calculate_op(a, b, find_position((tmp->content) - 1, a));
			if (((*cur_b + *cur_a) < (best) && *cur_a >= 0 && *cur_b >= 0) \
				|| best_num == INT_MAX)
			{
				best = *cur_a + *cur_b;
				best_num = tmp->content;
			}
			if (((*cur_b - *cur_a) < (-best) && *cur_a < 0 && *cur_b < 0) \
				|| best_num == INT_MAX)
			{
				best = -(*cur_a - *cur_b);
				best_num = tmp->content;
			}
		}
		tmp = tmp->next;
	}
	free(highest);
	return (best_num);
}

//finding the best possible number in stack a to push to stack b
//search for the number of operations to put best number from stack_a in stack_b
//plus number of operations needed to put this best number of stack_a to top
int	find_best_num(t_stack **stack_a, t_stack **stack_b, int rot_b)
{
	int		best_num;
	int		rot_a;

	rot_a = 0;
	best_num = opration_calculations(*stack_a, *stack_b, &rot_a, &rot_b);
	make_rotation(&rot_a, &rot_b, stack_a, stack_b);
	if ((ins_pos((*stack_b), best_num)) >= (count_nodes(*stack_b) / 2))
	{
		while ((ins_pos((*stack_b), best_num)) > 1)
			reverse_rotate_b(stack_b);
	}
	else
	{
		while ((ins_pos((*stack_b), best_num)) > 1)
			rotate_b(stack_b);
	}
	if ((find_position(best_num, *stack_a)) >= (count_nodes(*stack_a) / 2))
	{
		while (find_position(best_num, (*stack_a)) > 1)
			reverse_rotate_a(stack_a);
	}
	else
	{
		while (find_position(best_num, (*stack_a)) > 1)
			rotate_a(stack_a);
	}
	return (0);
}

// main algorithm for sorting the stack
void	sorting_algorithm(t_stack **a, t_stack **b)
{
	int	count;

	count = count_nodes(*a);
	if (count > 4)
	{
		while (count > 3)
		{
			find_best_num(a, b, 0);
			push_b(a, b);
			count--;
		}
		while (find_position((find_highest(*b)), (*b)) != 1)
			rotate_b(b);
	}
	if (count <= 3)
		short_algorithm(a, b, count);
	while (*b != NULL)
		push_a(a, b);
	return ;
}
