/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:09:37 by fkeitel           #+#    #+#             */
/*   Updated: 2024/01/03 15:07:53 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//
//	shifitng the nodes from the stack in reverse direction:
//

//shift down all elements of the stack and the last node becomes the first node
int	reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*temp2;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = *stack;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp2 = temp->next;
		temp->next = NULL;
		temp2->next = *stack;
		*stack = temp2;
		return (1);
	}
	return (0);
}

//shift down all elements of stack_a and the last node becomes the first node
void	reverse_rotate_a(t_list **stack_a)
{
	if (reverse_rotate(stack_a) == 1)
		ft_printf("rra\n");
}

//shift down all elements of stack_b and the last node becomes the first node
void	reverse_rotate_b(t_list **stack_b)
{
	if (reverse_rotate(stack_b) == 1)
		ft_printf("rrb\n");
}

//shift down all elements of stack_a and stack_b at the same time
//the last node becomes the first node
void	reverse_rotate_rr(t_list **stack_a, t_list **stack_b)
{
	if (reverse_rotate(stack_a) + reverse_rotate(stack_b) == 2)
		ft_printf("rrr\n");
}
