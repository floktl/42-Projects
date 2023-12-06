/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:54:49 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/05 18:00:29 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// function for finding the highest number in a stack
int	find_highest(t_stack *stack)
{
	int		highest;
	t_stack	*current;

	if (stack == NULL)
		return (0);
	highest = stack->content;
	current = stack->next;
	while (current != NULL)
	{
		if (current->content > highest)
			highest = current->content;
		current = current->next;
	}
	return (highest);
}

// function for finding the lowest number in a stack
int	find_lowest(t_stack *stack)
{
	int		lowest;
	t_stack	*current;

	if (stack == NULL)
		return (0);
	lowest = stack->content;
	current = stack->next;
	while (current != NULL)
	{
		if (current->content < lowest)
			lowest = current->content;
		current = current->next;
	}
	return (lowest);
}

// function for finding the position of a node in a stack
int	find_position(int num, t_stack *stack)
{
	int		position;
	t_stack	*current;

	if (stack == NULL)
		return (0);
	position = 1;
	current = stack;
	while (current != NULL)
	{
		if (current->content == num)
			return (position);
		position++;
		current = current->next;
	}
	return (0);
}

//function for counting the nodes in a stack
int	count_nodes(t_stack *stack)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = stack;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

//returning the last number of the stack
int	lstlast(t_stack *stack)
{
	t_stack	*lst;

	lst = stack;
	if (lst == NULL)
		return (lst->content);
	while (lst != NULL)
		lst = lst->next;
	return (lst->content);
}
