/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_help_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:31:06 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/06 22:16:53 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//
// functions for the sorting algorithmus
//

// function to find the correct insertion position
int	ins_pos(t_stack *stack, int num)
{
	t_stack	*current;
	int		save2;
	int		position;

	position = 0;
	if (stack == NULL)
		return (0);
	current = stack;
	save2 = INT_MIN;
	while (current != NULL)
	{
		if (num > current->content && current->content > save2)
		{
			save2 = current->content;
			position = find_position(save2, stack);
		}
		current = current->next;
	}
	if (save2 == INT_MIN)
		position = find_position(find_highest(stack), stack);
	return (position);
}

//calculate how many rotations are necessary, to push the top of-
//stack_a into stack_b in the correct order (descending)
int	calculate_op(t_stack *stack, int num, int op_b_minus, int pos)
{
	int	rotation_counter;
	int	sz;

	op_b_minus = 1;
	sz = count_nodes(stack);
	if ((sz % 2 == 0 && pos > (sz / 2)) || (sz % 2 != 0 && (sz - pos) <= pos))
		pos *= -1;
	rotation_counter = 0;
	if (-pos == sz - 1)
		return (0);
	while (pos > 0)
	{
		rotation_counter++;
		pos--;
	}
	if (pos < 0)
		pos = (sz + pos) * (-1);
	while (pos++ < 0)
		rotation_counter--;
	if (num < 0)
	{
		op_b_minus = -1;
		num *= -1;
	}
	return (rotation_counter);
}

//funct for counting nums of operations, necessary to put node to top of stack
int	calculate_rotations(t_stack *stack, int best_num, int op_a_minus)
{
	t_stack	*temp;
	int		op;
	int		sz;
	int		rotation_counter;

	if (stack == NULL)
		return (INT_MAX);
	temp = stack;
	op = find_position(best_num, temp);
	sz = count_nodes(stack);
	rotation_counter = 0;
	op_a_minus = 1;
	if (op == 1)
		return (0);
	op -= 1;
	if ((sz % 2 == 0 && op > (sz / 2)) || (sz % 2 != 0 && (sz - op) <= op))
		rotation_counter = op - sz - 1;
	else
		rotation_counter = op - 1;
	if (rotation_counter < 0)
	{
		op_a_minus = -1;
		rotation_counter *= -1;
	}
	return (rotation_counter);
}

//function for making the necessary rotations in the stack
int	make_rotation(int *i, int args, t_stack **stack_a, t_stack **stack_b)
{
	int	total_operations;

	total_operations = 0;
	while (*i > 0)
	{
		if (args == 'a')
			total_operations += rotate_a(stack_a);
		else if (args == 'b')
			total_operations += rotate_b(stack_b);
		else if (args == '2')
			total_operations += rotate_rr(stack_a, stack_b);
		(*i)--;
	}
	return (total_operations);
}
