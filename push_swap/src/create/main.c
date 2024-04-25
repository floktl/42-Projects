/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:58:32 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/25 18:53:40 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//
//	push_swap project by Florian Keitel
//	this program sorts a stack of random integers by their size
//	smallest num on top. Only limited operations and functions allowed
//

//	function to add the argument to stack_a
static int	pro_arg(t_list **stack, char **args)
{
	t_list	*new;
	int		i;

	i = 0;
	while (args[i])
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
			return (EXIT_FAILURE);
		new->content = (int)ft_atou(args[i]);
		new->next = NULL;
		ft_lstadd_back(stack, new);
		i++;
	}
	return (EXIT_SUCCESS);
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
			return (EXIT_FAILURE);
		i = 0;
		while ((*args)[i])
		{
			trimmed = ft_strtrim((*args)[i], " ");
			if (!trimmed)
				return (ft_free(*args), EXIT_FAILURE);
			free((*args)[i]);
			(*args)[i] = trimmed;
			i++;
		}
	}
	return (EXIT_SUCCESS);
}

//	function for initializing stacks, remving "" from argument if necessary
int	initstack(t_list **stack, int argc, char **argv)
{
	char	**args;
	int		i;

	args = NULL;
	if (split_arguments_into_array(argv, &args, argc) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (argc > 2)
	{
		args = malloc((argc) * sizeof(char *));
		if (!args)
			return (EXIT_FAILURE);
		i = 0;
		while (i <= argc && argv[i + 1])
		{
			args[i] = ft_strdup(argv[i + 1]);
			if (!args[i])
				return (ft_free(args), EXIT_FAILURE);
			i++;
		}
		args[i] = NULL;
	}
	if (check_arg(args) == EXIT_FAILURE || pro_arg(stack, args) == EXIT_FAILURE)
		return (ft_free(args), EXIT_FAILURE);
	ft_free(args);
	return (EXIT_SUCCESS);
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
	if (initstack(stack_a, argc, argv) == EXIT_FAILURE || argc < 2)
		return (free_stack(stack_a), free_stack(stack_b), -1);
	sorting_algorithm(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
