/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:31:17 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/18 18:31:32 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//
//	swapping the first two elements of a stack:
//

//swap the first 2 elements at the top of the stack
int	swap(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
	return (1);
}

//swap the first 2 elements at the top of stack_a
void	swap_a(t_stack **stack_a)
{
	if (swap(stack_a) == 1)
		printf("sa\n");
}

//swap the first 2 elements at the top of stack_b
void	swap_b(t_stack **stack_b)
{
	if (swap(stack_b) == 1)
		printf("sb\n");
}

//swap the first 2 elements at the top of stack_a stack_b at the same time
void	swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (swap(stack_b) + swap(stack_a) == 2)
		printf("ss\n");
}
