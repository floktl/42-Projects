/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_help_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:31:06 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/29 17:25:49 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//
// functions for the sorting algorithmus
//

int	find_last_element(t_stack *stack)
{
	t_stack	*current;

	if (stack == NULL)
	{
		printf("Stack is empty.\n");
		return (-1);
	}
	current = stack;
	while (current->next != NULL)
		current = current->next;
	return (current->content);
}

// function to find the correct insertion position
int	ins_pos(t_stack *stack_b, int num)
{
	t_stack	*counter_b;
	int		target;
	int		tmp;

	tmp = INT32_MIN;
	counter_b = stack_b;
	while (counter_b != NULL)
	{
		if ((counter_b->content < num)
			&& (counter_b->content > tmp))
		{
			tmp = counter_b->content;
			target = find_position(counter_b->content, stack_b);
		}
		counter_b = counter_b->next;
	}
	if (tmp == INT32_MIN)
		target = find_position(find_highest(stack_b), stack_b);
	return (target);
}

//calculate how many rotations are necessary, to push the top of-
//stack_a into stack_b in the correct order (descending)
int	calculate_op(t_stack *stack, int pos)
{
	t_stack	*temp;
	int		sz;

	temp = stack;
	sz = count_nodes(temp);
	if (sz <= 1 || pos <= 1)
		return (0);
	if ((sz % 2 == 0 && (pos <= ((sz / 2) + 2))) \
		|| (sz % 2 != 0 && pos <= ((sz) / 2 + 1)))
		return (pos - 1);
	else
		return ((sz - pos) * (-1) - 1);
	return (0);
}

//function for making the necessary rotations in the stack
int	rotate_both(int *a, int *b, t_stack **stack_a, t_stack **stack_b)
{
	while (*a > 0 && *b > 0)
	{
		rotate_rr(stack_a, stack_b);
		(*a)--;
		(*b)--;
	}
	while (*a < 0 && *b < 0)
	{
		reverse_rotate_rr(stack_a, stack_b);
		(*a)++;
		(*b)++;
	}
	return (0);
}
