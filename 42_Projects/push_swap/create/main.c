/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:58:32 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/06 23:06:36 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//
// push_swap project by Florian Keitel
// this program sorts a stack of random integers by their size
// smallest num on top. Only limited operations and functions allowed
//

int	main(int argc, char *argv[])
{
	int		count_arguments;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	count_arguments = argc - 1;
	if (check_error(count_arguments, argv, &stack_a, &stack_b) == 1)
		return (1);
	while (count_arguments-- > 0)
		push_new_node(&stack_a, ft_atou(argv[count_arguments + 1]));
	sorting_algorithm(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	return (0);
}
