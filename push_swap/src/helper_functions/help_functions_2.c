/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:54:49 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/25 21:48:39 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// function for finding the highest number in a stack
int	find_highest(t_list *stack)
{
	int		highest;
	t_list	*current;

	if (stack == NULL)
		return (0);
	highest = INT_MIN;
	current = stack;
	while (current != NULL)
	{
		if (current->content > highest)
			highest = current->content;
		current = current->next;
	}
	return (highest);
}

// function for finding the lowest number in a stack
int	find_lowest(t_list *stack)
{
	int		lowest;
	t_list	*current;

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
int	find_position(int num, t_list *stack)
{
	int		position;
	t_list	*current;

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
int	count_nodes(t_list *stack)
{
	int		count;
	t_list	*current;

	count = 0;
	current = stack;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

//function to check if the stack is sorted in descending order
int	check_if_sorted(t_list *stack)
{
	t_list	*current;

	if (stack == NULL || stack->next == NULL)
		return (1);
	current = stack;
	while (current->next != NULL)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
