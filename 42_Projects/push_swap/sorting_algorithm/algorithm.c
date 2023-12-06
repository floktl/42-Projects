/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:48:05 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/06 22:17:13 by fkeitel          ###   ########.fr       */
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
	int		best_a;
	int		best_b;
	int		a_minus;
	int		b_minus;
	int		best_num;

	best_num = INT_MAX;
	a_minus = 0;
	b_minus = 0;
	while (a != NULL)
	{
		*cur_b = calculate_op(b, a->content, b_minus, ins_pos(b, a->content));
		*cur_a = calculate_rotations(a, a->content, a_minus);
		if ((*cur_b + *cur_a) < (best_b + best_a) || best_num == INT_MAX)
		{
			best_a = *cur_a;
			best_b = *cur_a;
			best_num = a->content;
		}
		a = a->next;
	}
	*cur_a = best_a * a_minus;
	*cur_b = best_b * b_minus;
	return (best_num);
}

//finding the best possible number in stack a to push to stack b
//search for the number of operations to put best number from stack_a in stack_b
//plus number of operations needed to put this best number of stack_a to top
int	find_best_num(t_stack **stack_a, t_stack **stack_b, int num)
{
	t_stack	*temp_a;
	int		op_counter;
	int		best_num;
	int		cur_op_a;

	temp_a = *stack_a;
	op_counter = 0;
	best_num = opration_calculations(temp_a, *stack_b, &cur_op_a, &num);
	op_counter += make_rotation(&cur_op_a, '2', stack_a, stack_b);
	op_counter += make_rotation(&num, 'a', stack_a, stack_b);
	op_counter += make_rotation(&cur_op_a, 'a', stack_a, stack_b);
	while (num++ < 0)
		op_counter += reverse_rotate_b(stack_b);
	while (cur_op_a > 0)
	{
		op_counter += rotate_a(stack_a);
		cur_op_a--;
	}
	while (cur_op_a++ < 0)
		op_counter += reverse_rotate_a(stack_a);
	while ((ins_pos((*stack_b), best_num)) > 1)
		op_counter += rotate_b(stack_b);
	while (find_position(best_num, (*stack_a)) > 1)
		op_counter += rotate_a(stack_a);
	return (op_counter);
}

// main algorithm for sorting the stack
void	sorting_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	count = push_b(stack_a, stack_b);
	if ((count_nodes(*stack_b) == 1) \
		&& ((*stack_a)->content < (*stack_b)->content))
		count += swap_b(stack_b);
	count += push_b(stack_a, stack_b);
	while ((*stack_a) != NULL)
	{
		count += find_best_num(stack_a, stack_b, 0);
		count += push_b(stack_a, stack_b);
	}
	while (find_position((find_highest(*stack_b)), (*stack_b)) != 1)
		count += rotate_b(stack_b);
	while (*stack_b != NULL)
		count += push_a(stack_a, stack_b);
	printf("\n%d\n", count);
	return ;
}
