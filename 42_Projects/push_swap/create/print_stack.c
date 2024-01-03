/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:02:40 by fkeitel           #+#    #+#             */
/*   Updated: 2024/01/03 07:53:28 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//
//	functions for printing stacks, isnt necessary, but great for visualization
//	just have a look
//

//function for ensuring alignment for the stacks displayed in terminal
void	print_spaces(t_list *stack, int type, int max_stack)
{
	int		count;
	t_list	*temp;

	count = 0;
	temp = stack;
	if (type == 2)
	{
		while (count++ < max_stack + 8)
			printf("_");
		printf("\n");
	}
	if (type == 1)
	{
		while (count++ < max_stack)
			printf(" ");
	}
	if (type == 0 && temp != NULL)
	{
		while (count <= (int)(max_stack - ft_strlen(ft_itoa(temp->content))))
		{
			printf(" ");
			count++;
		}
	}
}

//function for printing one node
int	print_one_node(t_list **stack, int max_length, int diff)
{
	if (*stack != NULL)
	{
		print_spaces(*stack, 0, max_length);
		printf("%d", (*stack)->content);
		*stack = (*stack)->next;
	}
	return (diff);
}

//function for printing spaces between a and b, for perfect allignment
void	print_spaces_in_between(t_list **b, int *diff, int len_a, int len_b)
{
	if (*diff <= 0)
	{
		if (*diff != 0)
		{
			while (len_a >= 0)
			{
				printf(" ");
				len_a--;
			}
		}
		printf("   ");
		*diff = print_one_node(b, len_b, *diff);
	}
	printf("\n");
	if (*diff > 0)
		(*diff)--;
	if (*diff < 0)
		(*diff)++;
	return ;
}

//function to actually print the nodes alligned
int	printing_nodes(t_list *temp_a, t_list *temp_b, int len_a, int len_b)
{
	int	diff;
	int	counter;
	int	count;
	int	i;

	i = 0;
	count = 1;
	diff = stack_length(temp_a) - stack_length(temp_b);
	counter = ft_strlen(ft_itoa(count_nodes(temp_b)));
	if (count_nodes(temp_b) < count_nodes(temp_a))
		counter = ft_strlen(ft_itoa(count_nodes(temp_a)));
	while (temp_a || temp_b)
	{
		while (i++ < (counter - (int)ft_strlen(ft_itoa(count))))
			printf(" ");
		i = 0;
		printf("%d: ", count++);
		if (diff >= 0)
			diff = print_one_node(&temp_a, len_a, diff);
		print_spaces_in_between(&temp_b, &diff, len_a, len_b);
	}
	return (diff);
}

//printing stacks starting with top of highest stack, incl diff between stacks
void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		max_length_a;
	int		max_length_b;

	max_length_a = stack_biggest_str_length(stack_a);
	max_length_b = stack_biggest_str_length(stack_b);
	temp_a = stack_a;
	temp_b = stack_b;
	printf("\n");
	printing_nodes(temp_a, temp_b, max_length_a, max_length_b);
	print_spaces(temp_a, 2, max_length_a + max_length_b);
	print_spaces(temp_a, 1, max_length_a);
	printf("   a |");
	print_spaces(temp_b, 1, max_length_b);
	printf("b |\n");
}
