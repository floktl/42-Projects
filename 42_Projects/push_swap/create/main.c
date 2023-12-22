/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:58:32 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/19 15:42:35 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//
// push_swap project by Florian Keitel
// this program sorts a stack of random integers by their size
// smallest num on top. Only limited operations and functions allowed
//
void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

void	free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

t_stack	*ft_lst_new(int content)
{
	t_stack	*new_node;

	new_node = NULL;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lst_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

int	initstack(t_stack **stack, int argc, char **argv)
{
	t_stack	*new;
	char	**args;
	int		i;
	int		count_arguments;

	i = 0;
	count_arguments = argc;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lst_new((int)ft_atou(args[i]));
		ft_lst_add_back(stack, new);
		if (check_error(count_arguments, args) == -1)
			return (-1);
		i++;
	}
	if (argc == 2)
		ft_free(args);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc < 2)
		return (-1);
	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	stack_b = (t_stack **)malloc(sizeof(t_stack *));/
	if (!stack_a || !stack_b)
		return (-1);
	*stack_a = NULL;
	*stack_b = NULL;
	if (initstack(stack_a, argc, argv) == -1)
		return (-1);
	sorting_algorithm(stack_a, stack_b);
	//print_stacks(*stack_a, *stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
