/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:48:05 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/26 09:53:40 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
//
//	algorithms for sorting the stack_a, the smallest number on the top:
//

//	helper function to return best number of operations and the number itself
int	ret_best(int a, int b, int cur_num, int *lowest_operations)
{
	int	best_num;

	if (a >= b)
		*lowest_operations = a;
	best_num = cur_num;
	if (b > a)
		*lowest_operations = b;
	return (best_num);
}

//	function for finding the lowest operations
//	if rot_a and rot_b are positive, the best number is only the highest
int	find_low_op(int rot_a, int rot_b, int cur_num, int *best)
{
	static int	best_num = INT_MIN;

	if (((rot_a + rot_b) < *best || *best == INT_MIN)
		&& rot_a >= 0 && rot_b >= 0)
		best_num = ret_best(rot_a, rot_b, cur_num, best);
	else if (((-rot_a - rot_b) < *best || *best == INT_MIN)
		&& rot_a <= 0 && rot_b <= 0)
		best_num = ret_best(-rot_a, -rot_b, cur_num, best);
	else if (((rot_a - rot_b) < *best || *best == INT_MIN)
		&& rot_a > 0 && rot_b < 0)
		best_num = ret_best(rot_a, -rot_b, cur_num, best);
	else if (((-rot_a + rot_b) < *best || *best == INT_MIN)
		&& rot_a < 0 && rot_b > 0)
		best_num = ret_best(-rot_a, rot_b, cur_num, best);
	return (best_num);
}

//	calculate the minumum operations necessary to push the best num
//	from stack_a to stack_b
//	iterates stack_a, and calculates the lowest number of rotations
//	in both stacks needed for the current number to push to stack_b
//	negative number for reverse rotate, positive for rotate
int	op_calc(t_list *a, t_list *b, int *rot_a, int *rot_b)
{
	t_list	*tmp;
	int		best;
	int		best_num;
	int		*big;

	tmp = a;
	big = find_three_highest(tmp);
	best_num = INT_MIN;
	best = INT_MAX;
	while (tmp != NULL)
	{
		if (tmp->content != big[0] && tmp->content != big[1]
			&& tmp->content != big[2])
		{
			*rot_a = calculate_op(a, find_position((tmp->content), a));
			*rot_b = calculate_op(b, ins_pos(b, tmp->content));
			best_num = find_low_op(*rot_a, *rot_b, tmp->content, &best);
		}
		tmp = tmp->next;
	}
	free(big);
	*rot_a = calculate_op(a, find_position((best_num), a));
	*rot_b = calculate_op(b, ins_pos(b, best_num));
	return (best_num);
}

//	finding the best possible number in stack a to push to stack b
//	search for number of operations to put best number from stack_a in stack_b
//	plus number of operations needed to put this best number of stack_a to top
int	prepare_and_push(t_list **a, t_list **b, int rot_a, int rot_b)
{
	while (rot_b < 0)
	{
		reverse_rotate_b(b);
		rot_b++;
	}
	while (rot_b > 0)
	{
		rotate_b(b);
		rot_b--;
	}
	while (rot_a < 0)
	{
		reverse_rotate_a(a);
		rot_a++;
	}
	while (rot_a > 0)
	{
		rotate_a(a);
		rot_a--;
	}
	push_b(a, b);
	return (0);
}

//	main algorithm for sorting the stack
//	first searching for the best num with the least oparation needed to push to
//	stack_b. Then rotating two stacks at once, if possible to save operations
//	Then preparing the stacks for pushing the best num into stack_b by rotating
//	Then push best num.... and again the same, until only three nodes in stack_a
//	after that rotating the stack_b until the highest number is on top
//	After that a small algorithm under 3 nodes
//	in the end pushing the sorted stack_b into a-> sorted stack_a
//	boooom-> finally done! easy or?
void	sorting_algorithm(t_list **stack_a, t_list **stack_b)
{
	int	rot_a;
	int	rot_b;

	rot_a = 0;
	rot_b = 0;
	if (check_if_sorted(*stack_a) == 1)
		return ;
	if (count_nodes(*stack_a) > 3)
	{
		while (count_nodes(*stack_a) > 3)
		{
			op_calc(*stack_a, *stack_b, &rot_a, &rot_b);
			rotate_both(&rot_a, &rot_b, stack_a, stack_b);
			prepare_and_push(stack_a, stack_b, rot_a, rot_b);
		}
		rot_highest_to_top(stack_b);
	}
	short_algorithm(stack_a, count_nodes(*stack_a));
	while (*stack_b != NULL)
		push_a(stack_a, stack_b);
	if (check_if_sorted(*stack_a) == 0)
		ft_printf("the stack is not properly sorted");
	return ;
}
