/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:30:09 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/25 21:49:08 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//
//	shifitng the nodes from the stack:
//

//shift up all elements of the stack and the first node becomes the last node
int	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*temp2;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	temp = *stack;
	temp2 = *stack;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = temp;
	*stack = temp->next;
	temp->next = NULL;
	return (1);
}

//shift up all elements of stack_a and the first node becomes the last node
void	rotate_a(t_list **stack_a)
{
	if (rotate(stack_a) == 1)
		ft_printf("ra\n");
}

//shift up all elements of stack_b and the first node becomes the last node
void	rotate_b(t_list **stack_b)
{
	if (rotate(stack_b) == 1)
		ft_printf("rb\n");
}

//shift up all elements of stack_a and stack_b at the same time
//the first node becomes the last node
void	rotate_rr(t_list **stack_a, t_list **stack_b)
{
	if (rotate(stack_a) + rotate(stack_b) == 2)
		ft_printf("rr\n");
}
