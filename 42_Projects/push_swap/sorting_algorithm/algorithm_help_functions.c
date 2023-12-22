/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_help_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:31:06 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/22 18:46:13 by fkeitel          ###   ########.fr       */
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
int	calculate_op(t_stack *stack_a, t_stack *stack_b, int pos)
{
	t_stack	*temp;
	int		sz;

	temp = stack_a;
	temp = stack_b;
	sz = count_nodes(temp);
	if ((sz % 2 == 0 && pos <= (sz / 2)) || (sz % 2 != 0 && pos < (sz + 1) / 2))
		return (pos);
	else
		return ((sz - pos) * -1);
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
