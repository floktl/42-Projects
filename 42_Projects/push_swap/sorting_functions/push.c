/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:52:51 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/05 16:49:21 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//
//	move or remove nodes from stack to stack:
//

//adding new node to a stack at the top
void	push_new_node(t_stack **t_head, int content)
{
	t_stack	*new_node;

	new_node = (t_stack *) malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->content = content;
	new_node->next = *t_head;
	*t_head = new_node;
}

//move the top node of one stack to the top node of the other stack
int	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*temp;

	temp = NULL;
	if (*stack_2 != NULL)
	{
		temp = *stack_2;
		*stack_2 = (*stack_2)->next;
		temp->next = *stack_1;
		*stack_1 = temp;
		return (1);
	}
	return (0);
}

//move top from stack_b to top of stack_a
int	push_a(t_stack **stack_a, t_stack **stack_b)
{
	return (push(stack_a, stack_b));
}

//move top from stack_a to top of stack_b
int	push_b(t_stack **stack_a, t_stack **stack_b)
{
	return (push(stack_b, stack_a));
}
