/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:41:05 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/25 21:48:34 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//
//	helper functions, or modifies existing functions:
//

//find the 3 highest number in a stack
int	*find_three_highest(t_list *stack)
{
	t_list	*temp;
	int		*highest;
	int		value;

	temp = stack;
	highest = (int *)malloc(3 * sizeof(int));
	if (!highest)
		return (0);
	highest[0] = INT_MIN;
	highest[1] = INT_MIN;
	highest[2] = INT_MIN;
	while (temp != NULL)
	{
		value = temp->content;
		check_which_highest(&highest, value);
		temp = temp->next;
	}
	return (highest);
}

//function to save highest numbers in an array
void	check_which_highest(int **highest, int value)
{
	if (value > (*highest)[0])
	{
		(*highest)[2] = (*highest)[1];
		(*highest)[1] = (*highest)[0];
		(*highest)[0] = value;
	}
	else if (value > (*highest)[1])
	{
		(*highest)[2] = (*highest)[1];
		(*highest)[1] = value;
	}
	else if (value > (*highest)[2])
		(*highest)[2] = value;
}

//function to count length of the longest string in the stack
int	stack_biggest_str_length(t_list *stack)
{
	int		str_length;
	int		cur_str;
	t_list	*temp;

	str_length = 0;
	cur_str = 0;
	temp = stack;
	while (temp)
	{
		cur_str = ft_strlen(ft_itoa(temp->content));
		if (cur_str > str_length)
			str_length = cur_str;
		temp = temp->next;
	}
	return (str_length);
}

// Helper function to count the number of elements in a stack
int	stack_length(t_list *stack)
{
	int		length;
	t_list	*temp;

	length = 0;
	temp = stack;
	while (temp)
	{
		length++;
		temp = temp->next;
	}
	return (length);
}

//modified atoi function to return an unsigned int for checking range of int
long	ft_atou(const char *str)
{
	int		sign;
	int		count;
	long	result;

	sign = 1;
	count = 0;
	result = 0;
	while (str[count] == ' ' || (str[count] >= '\t' && str[count] <= '\r'))
		count++;
	if (str[count] == '-')
		sign = -1;
	while (str[count] == '-' || str[count] == '+')
		count++;
	while (str[count] >= '0' && str[count] <= '9')
	{
		while (ft_isdigit(str[count]))
		{
			result *= 10;
			result += str[count] - '0';
			count++;
		}
	}
	return (result * sign);
}
