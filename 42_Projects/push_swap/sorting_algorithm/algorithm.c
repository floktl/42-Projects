/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:48:05 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/29 18:46:13 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//
//	algorithms for sorting the stack_a, the smallest number on the top:
//

int	ret_best(int a, int b, int cur_num, int *lowest_operations)
{
	int	best_num;

	if (a >= b)
		*lowest_operations = a;
	best_num = cur_num;
	if (b > a)
		*lowest_operations = b;
	//printf("a: %d b: %d best num: %d\n", a, b, *lowest_operations);
	return (best_num);
}

int	find_lowest_op(int cur_a, int cur_b, int cur_num, int *best_num, int best)
{
	if (((cur_a + cur_b) < best && cur_a >= 0 && cur_b >= 0)
		|| *best_num == INT_MIN)
		*best_num = ret_best(cur_a, cur_b, cur_num, &best);
	else if (((-cur_a - cur_b) < best && cur_a <= 0 && cur_b <= 0)
		|| *best_num == INT_MIN)
		*best_num = ret_best(-cur_a, -cur_b, cur_num, &best);
	else if (((cur_a - cur_b) < best && cur_a > 0 && cur_b < 0)
		|| *best_num == INT_MIN)
		*best_num = ret_best(cur_a, -cur_b, cur_num, &best);
	else if (((-cur_a + cur_b) < best && cur_a < 0 && cur_b > 0)
		|| *best_num == INT_MIN)
		*best_num = ret_best(-cur_a, cur_b, cur_num, &best);
	return (best);
}

//calculate the minumum operations necessary to push the best num
//from stack_a to stack_b
//iterates stack_a, and calculates the lowest number of rotations
// in both stacks needed for the current number to push to stack_b
//negative number for reverse rotate, positive for rotate
int	op_calc(t_stack *a, t_stack *b, int *cur_a, int *cur_b)
{
	t_stack	*tmp;
	int		best;
	int		best_num;
	int		*big;

	tmp = a;
	big = find_three_highest(tmp);
	best_num = INT_MIN;
	best = INT_MIN;
	while (tmp != NULL)
	{
		if (tmp->content != big[0] && tmp->content != big[1] \
			&& tmp->content != big[2])
		{

			//printf("a: %d b: %d, stack_size_a %d, stack_size_b: %d\n", find_position((tmp->content), a), ins_pos(b, tmp->content), count_nodes(a), count_nodes(b));
			*cur_a = calculate_op(a, find_position((tmp->content), a));
			*cur_b = calculate_op(b, ins_pos(b, tmp->content));
			//printf("Cur_a: %d cur_b %d\n", *cur_a, *cur_b);
			best = find_lowest_op(*cur_a, *cur_b, tmp->content, &best_num, best);
			//printf("best %d\n", best);
		}
		tmp = tmp->next;
	}
	//print_stacks(a, b);
	free(big);
	*cur_a = calculate_op(a, find_position((best_num), a));
	*cur_b = calculate_op(b, ins_pos(b, best_num));
	return (best_num);
}

//finding the best possible number in stack a to push to stack b
//search for the number of operations to put best number from stack_a in stack_b
//plus number of operations needed to put this best number of stack_a to top
int	prepare_and_push(t_stack **a, t_stack **b, int rot_a, int rot_b)
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

void	rot_highest_to_top(t_stack **stack_b)
{
	while ((find_position((find_highest(*stack_b)), (*stack_b)))
		!= 1 && (find_position((find_highest(*stack_b)), (*stack_b))
			<= (count_nodes(*stack_b) / 2)))
		rotate_b(stack_b);
	while ((find_position((find_highest(*stack_b)), (*stack_b)))
		!= 1 && (find_position((find_highest(*stack_b)), (*stack_b))
			> (count_nodes(*stack_b) / 2)))
		reverse_rotate_b(stack_b);
}
// main algorithm for sorting the stack
//first searching for the best num with the least oparation needed to push to
// stack_b. Then rotating two stacks at once, if possible to save operations
//Then preparing the stacks for pushing the best num into stack_b  by rotating
//Then push best num.... and again the same, until only three nodes in stack_a
//after that rotating the stack_b until the highest number is on top
//After that a small algorithm under 3 nodes
//in the end pushing the sorted stack_b into a-> sorted stack_a
//boooom-> finally done! easy or?
void	sorting_algorithm(t_stack **stack_a, t_stack **stack_b)
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
		printf("the stack is not properly sorted");
	return ;
}
