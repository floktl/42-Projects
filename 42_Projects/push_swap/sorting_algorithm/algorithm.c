/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:48:05 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/22 20:10:31 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//
//	algorithms for sorting the stack_a, the smallest number on the top:
//

//calculate the minumum operations necessary to push the best num
//from stack_a to stack_b
int	op_calc(t_stack *a, t_stack *b, int *cur_a, int *cur_b)
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
			if (((*cur_b - *cur_a) < (-best) && *cur_a <= 0 && *cur_b < 0) \
				|| best_num == INT_MAX)
			{
				best = -(*cur_a - *cur_b);
				best_num = tmp->content;
			}
			//print_stacks(a, b);
			//printf("a: %d b: %d best: %d\n", find_position((tmp->content) - 1, a), ins_pos(b, tmp->content), best);
			//if ((ins_pos(b, tmp->content) < find_position((tmp->content) - 1, a)) \
			//	&& (((find_position((tmp->content) - 1, a)) - ins_pos(b, tmp->content)) < best    ))
			//{
			//	printf("test");
			//	*cur_a = find_position((tmp->content) - 1, a);
			//	*cur_b = ins_pos(b, tmp->content);
			//	best = ins_pos(b, tmp->content);
			//	best_num = tmp->content;
			//}
		}
		tmp = tmp->next;
	}
	free(highest);
	return (best_num);
}

//finding the best possible number in stack a to push to stack b
//search for the number of operations to put best number from stack_a in stack_b
//plus number of operations needed to put this best number of stack_a to top
int	prepare_to_push(t_stack **stack_a, t_stack **stack_b, int best_num)
{
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
//first searching for the best num with the least oparation needed to push to
// stack_b. Then rotating two stacks at once, if possible to save operations
//Then preparing the stacks for pushing the best num into stack_b  by rotating
//Then push best num.... and again the same, until only three nodes in stack_a
//after that rotating the stack_b until the highest number is on top
//After that a small algorithm under 3 nodes
//in the end pushing the sorted stack_b into a-> sorted stack_a
//boooom-> finally done! easy or?
void	sorting_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	best_num;
	int	rot_a;
	int	rot_b;

	rot_a = 0;
	rot_b = 0;
	if (count_nodes(*stack_a) > 3)
	{
		while (count_nodes(*stack_a) > 3)
		{
			best_num = op_calc(*stack_a, *stack_b, &rot_a, &rot_b);
			rotate_both(&rot_a, &rot_b, stack_a, stack_b);
			prepare_to_push(stack_a, stack_b, best_num);
			push_b(stack_a, stack_b);
		}
		while (find_position((find_highest(*stack_b)), (*stack_b)) != 1)
			rotate_b(stack_b);
	}
	if (count_nodes(*stack_a) <= 3)
		short_algorithm(stack_a, stack_b, count_nodes(*stack_a));
	while (*stack_b != NULL)
		push_a(stack_a, stack_b);
	return ;
}
