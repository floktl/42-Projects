/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:58:32 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/26 09:50:13 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//
//	push_swap project by Florian Keitel
//	this program sorts a stack of random integers by their size
//	smallest num on top. Only limited operations and functions allowed
//

//	function to add the argument to stack_a
static int	process_args(t_list **stack, char **args)
{
	t_list	*new;
	int		i;

	i = 0;
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

//	function to split argument in two dimens. array if argument is in bracket
int	split_arguments_into_array(char **argv, char ***args, int argc)
{
	char	*trimmed;
	int		i;

	if (argc == 2)
	{
		*args = ft_split(argv[1], ' ');
		if (!(*args))
			return (-1);
		i = 0;
		while ((*args)[i])
		{
			trimmed = ft_strtrim((*args)[i], " ");
			if (!trimmed)
				return (ft_free(*args), -1);
			free((*args)[i]);
			(*args)[i] = trimmed;
			i++;
		}
	}
	return (0);
}

//	function for initializing stacks, remving "" from argument if necessary
int	initstack(t_list **stack, int argc, char **argv)
{
	char	**args;
	int		i;

	args = NULL;
	if (split_arguments_into_array(argv, &args, argc) == -1)
		return (-1);
	else if (argc > 2)
	{
		args = malloc((argc - 1) * sizeof(char *));
		if (!args)
			return (-1);
		i = 1;
		while (argv[i])
		{
			args[i - 1] = ft_strdup(argv[i]);
			if (!args[i - 1])
				return (ft_free(args), -1);
			i++;
		}
		args[i - 1] = NULL;
	}
	if (check_error(args) == -1 || process_args(stack, args) == -1)
		return (ft_free(args), -1);
	ft_free(args);
	return (0);
}

//	main function, first the stacks will be created, stack a will be filled
//	with the numbers given as argument, a few error checks will be made
//	then the actual sorting algorythm, followed by freeing the stacks
int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	stack_a = (t_list **)malloc(sizeof(t_list *));
	if (!stack_a)
		return (-1);
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack_b)
		return (free(stack_a), -1);
	*stack_a = NULL;
	*stack_b = NULL;
	if (initstack(stack_a, argc, argv) == -1 || argc < 2)
		return (free_stack(stack_a), free_stack(stack_b), -1);
	sorting_algorithm(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
