/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_help_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:31:06 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/25 21:48:48 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//
//	functions for the sorting algorithmus
//

//function for returning the content of the last element of a stack
int	find_last_element(t_list *stack)
{
	t_list	*current;

	if (stack == NULL)
	{
		ft_printf("Stack is empty.\n");
		return (-1);
	}
	current = stack;
	while (current->next != NULL)
		current = current->next;
	return (current->content);
}

// function to find the correct insertion position
int	ins_pos(t_list *stack_b, int num)
{
	t_list	*counter_b;
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
int	calculate_op(t_list *stack, int pos)
{
	t_list	*temp;
	int		sz;

	temp = stack;
	sz = count_nodes(temp);
	if (sz <= 1 || pos <= 1)
		return (0);
	if ((sz % 2 == 0 && (pos <= ((sz / 2) + 2)))
		|| (sz % 2 != 0 && pos <= ((sz) / 2 + 1)))
		return (pos - 1);
	else
		return ((sz - pos) * (-1) - 1);
	return (0);
}

//function for making the necessary rotations in the stack
int	rotate_both(int *a, int *b, t_list **stack_a, t_list **stack_b)
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

//function for rotating a sorted stack, until the highest number is on top
void	rot_highest_to_top(t_list **stack_b)
{
	while ((find_position((find_highest(*stack_b)), (*stack_b)))
		!= 1 && (find_position((find_highest(*stack_b)), (*stack_b))
			<= (count_nodes(*stack_b) / 2)))
		rotate_b(stack_b);
	while ((find_position((find_highest(*stack_b)), (*stack_b)))
		!= 1 && (find_position((find_highest(*stack_b)), (*stack_b))
			> (count_nodes(*stack_b) / 2)))
		reverse_rotate_b(stack_b);
}
