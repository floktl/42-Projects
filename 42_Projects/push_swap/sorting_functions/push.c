/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:52:51 by fkeitel           #+#    #+#             */
/*   Updated: 2024/01/03 15:07:41 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//
//	move or remove nodes from stack to stack:
//

//move the top node of one stack to the top node of the other stack
int	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*temp;

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
void	push_a(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == 1)
		ft_printf("pa\n");
}

//move top from stack_a to top of stack_b
void	push_b(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == 1)
		ft_printf("pb\n");
}
