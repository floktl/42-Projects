/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:46:27 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/19 12:10:03 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//
//	errors in the arguments:
//

//checking for errors in the arguments
int	check_argument_error(int n, char *argv[])
{
	int		i;
	long	current_number;
	int		*current_arg;

	i = 1;
	if (n == 0)
		return (1);
	current_arg = malloc(n * sizeof(int));
	if (!current_arg)
		return (1);
	while (i <= n)
	{
		current_number = ft_atou(argv[i]);
		if (check_for_duplicates(current_arg, current_number, i - 1) || \
			check_if_num_is_in_int_range(current_number, current_arg) || \
			check_if_num_is_digit(argv, current_arg, i))
			return (1);
		current_arg[i - 1] = current_number;
		i++;
	}
	free (current_arg);
	return (0);
}

//checking for duplicates in the argc arguments
int	check_for_duplicates(int *numbers, long cur_number, int cur_index)
{
	int	j;

	j = 0;
	while (j < cur_index)
	{
		if (numbers[j] == cur_number)
		{
			printf("Error\n");
			free (numbers);
			return (1);
		}
		j++;
	}
	return (0);
}

//check if the current parameter from argv is in the range of an Integer
int	check_if_num_is_in_int_range(long current_number, int *numbers)
{
	if (current_number <= INT_MIN || current_number >= INT_MAX)
	{
		printf("Error\n");
		free (numbers);
		return (1);
	}
	return (0);
}

//check if the current parameter from argv is in the range of an Integer
int	check_if_num_is_digit(char *argv[], int *numbers, int cur_index)
{
	int	j;

	j = 0;
	while (argv[cur_index][j] != '\0')
	{
		while (argv[cur_index][j] == '-' || argv[cur_index][j] == '+')
			j++;
		if (ft_isdigit((int)argv[cur_index][j]) == 0)
		{
			printf("Error\n");
			free (numbers);
			return (1);
		}
		j++;
	}
	return (0);
}
