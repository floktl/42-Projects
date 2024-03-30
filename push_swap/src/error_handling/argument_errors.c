/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:46:27 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/26 09:32:13 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
//
//	errors in the arguments:
//

//	checking for errors in the arguments
int	check_argument_error(char **args)
{
	long	current_number;
	int		n;

	n = 0;
	while (args[n])
	{
		current_number = ft_atou(args[n]);
		if (check_for_duplicates(args, current_number) == 1
			|| check_if_num_is_in_int_range(current_number)
			|| check_if_num_is_digit(args, n))
			return (1);
		n++;
	}
	return (0);
}

//	checking for duplicates in the argc arguments
int	check_for_duplicates(char **args, long cur_number)
{
	int	j;
	int	counter;

	j = 1;
	counter = 0;
	while (args[j])
	{
		if (ft_atou(args[j]) == cur_number)
		{
			counter++;
		}
		j++;
	}
	if (counter >= 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

//	check if the current parameter from argv is in the range of an Integer
int	check_if_num_is_in_int_range(long current_number)
{
	if (current_number <= INT_MIN || current_number >= INT_MAX)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

//	check if the current parameter from argv is in the range of an Integer
int	check_if_num_is_digit(char **args, int cur_index)
{
	int	j;

	j = 0;
	while (args[cur_index][j] != '\0')
	{
		while (args[cur_index][j] == '-' || args[cur_index][j] == '+')
			j++;
		if (!ft_isdigit(args[cur_index][j]))
		{
			ft_printf("Error\n");
			return (1);
		}
		j++;
	}
	return (0);
}
