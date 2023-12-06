/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blah.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:34:50 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/02 20:06:39 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include <limits.h>

int	find_highest(int *array, int size)
{
	int	i;
	int	highest;

	if (size <= 0)
		return (0);
	highest = array[0];
	i = 1;
	while (i < size)
	{
		if (array[i] > highest)
			highest = array[i];
		i++;
	}
	return (highest);
}

int	find_position(int num, int *array, int size)
{
	int	i;

	i = 0;
	while (array[i] != '\0')
	{
		if (array[i] == (num + 1))
			return (0);
		if (array[i] == num)
			return (i + 1);
		i++;
	}
	return (0);
}

int	calculate_rotations(int *array, int size, int num)
{
	int	target;
	int	pos;
	int	rotation_counter;

	if (num == 1)
		target = find_highest(array, size);
	else
		target = num - 1;
	pos = find_position(target, array, size) - 1;
	if ((size % 2 == 0 && pos > (size / 2))
		|| (size % 2 != 0 && (size - pos) <= pos))
		pos *= -1;
	rotation_counter = 0;
	if (-pos == size - 1)
		return (-1);
	while (pos > 0)
	{
		rotation_counter++;
		pos--;
	}
	if (pos < 0)
		pos = (size + pos) * (-1);
	while (pos++ < 0)
		rotation_counter--;
	return (rotation_counter);
}

int	main(void)
{
	int	stack[] = {3, 2, 1, 6, 7, 4};
	int	num_to_push = 5;
	int	stack_size = sizeof(stack) / sizeof(stack[0]);
	int	rotations_needed;

	rotations_needed = calculate_rotations(stack, stack_size, num_to_push);
	if (rotations_needed == INT_MIN)
		return (-1);
	if (rotations_needed >= 0)
		printf("Perform 'rb' %d times, then 'pb'.\n", rotations_needed);
	if (rotations_needed < 0)
		printf("Perform 'rrb' %d times, then 'pb'.\n", rotations_needed);
	return (0);
}
