/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:58:32 by fkeitel           #+#    #+#             */
/*   Updated: 2024/01/18 02:03:48 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//
//	push_swap project by Florian Keitel
//	this program sorts a stack of random integers by their size
//	smallest num on top. Only limited operations and functions allowed
//

//function to add the argument to stack_a
static int	process_args(t_list **stack, char **args, int i)
{
	t_list	*new;

	while (args[i])
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
			return (-1);
		new->content = (int)ft_atou(args[i]);
		new->next = NULL;
		ft_lstadd_back(stack, new);
		i++;
	}
	return (0);
}

//function for initializing stacks, remving "" from argument if necessary
int	initstack(t_list **stack, int argc, char **argv)
{
	char	**args;
	int		i;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (-1);
		i = 0;
	}
	else
	{
		args = argv;
		i = 1;
	}
	if (check_error(i, args) == -1 || process_args(stack, args, i) == -1)
		return (-1);
	if (argc == 2)
		ft_free(args);
	return (0);
}

//main function, first the stacks will be created, stack a will be filled
// with the numbers given as argument, a few error checks will be made
//then the actual sorting algorythm, followed by freeing the stacks
int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	stack_a = (t_list **)malloc(sizeof(t_list *));
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack_a || !stack_b)
		return (-1);
	*stack_a = NULL;
	*stack_b = NULL;
	if (initstack(stack_a, argc, argv) == -1 || argc < 2)
		return (free_stack(stack_a), free_stack(stack_b), -1);
	sorting_algorithm(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	//system("leaks push_swap");
	return (0);
}
