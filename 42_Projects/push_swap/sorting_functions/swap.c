/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:31:17 by fkeitel           #+#    #+#             */
/*   Updated: 2024/01/03 15:08:21 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//
//	swapping the first two elements of a stack:
//

//swap the first 2 elements at the top of the stack
int	swap(t_list **stack)
{
	int	temp;
	int	temp2;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = (*stack)->content;
		temp2 = (*stack)->next->content;
		(*stack)->next->content = temp;
		(*stack)->content = temp2;
		return (1);
	}
	return (0);
}

//swap the first 2 elements at the top of stack_a
void	swap_a(t_list **stack_a)
{
	if (swap(stack_a) == 1)
		ft_printf("sa\n");
}

//swap the first 2 elements at the top of stack_b
void	swap_b(t_list **stack_b)
{
	if (swap(stack_b) == 1)
		ft_printf("sb\n");
}

//swap the first 2 elements at the top of stack_a stack_b at the same time
void	swap_ss(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_b) + swap(stack_a) == 2)
		ft_printf("ss\n");
}
