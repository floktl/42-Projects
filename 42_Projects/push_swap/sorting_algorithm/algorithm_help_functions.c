/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_help_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:31:06 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/27 12:40:28 by flo              ###   ########.fr       */
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
	int		save;
	int		position;

	position = 0;
	if (stack == NULL)
		return (0);
	current = stack;
	save = INT_MIN;
	while (current != NULL)
	{
		if (num > current->content && current->content > save)
		{
			save = current->content;
			position = find_position(save, stack);
		}
		current = current->next;
	}
	if (save == INT_MIN)
		position = find_position(find_highest(stack), stack);
	if (position == 0)
		return (1);
	return (position);
}

//calculate how many rotations are necessary, to push the top of-
//stack_a into stack_b in the correct order (descending)
int	calculate_op(t_stack *stack, int pos)
{
	t_stack	*temp;
	int		sz;

	temp = stack;
	sz = count_nodes(temp);
	printf("pos: %d\n", pos);
	if (sz <= 2 || pos <= 1)
		return (0);
	if ((sz % 2 == 0 && pos <= (sz / 2)) || (sz % 2 != 0 && pos < (sz) / 2))
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
