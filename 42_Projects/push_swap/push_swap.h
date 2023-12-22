/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:57:56 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/19 11:50:16 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
//	header file:
//

//libraries:
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <stdarg.h>
# include <string.h>
# include <limits.h>

//single linked list for the two stacks:
typedef struct s_node_a
{
	int				content;
	struct s_node_a	*next;
}	t_stack;

//main functions:
int		main(int argc, char *argv[]);
//print stacks
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
int		printing_nodes(t_stack *temp_a, t_stack *temp_b, int len_a, int len_b);
int		print_one_node(t_stack **stack, int max_length, int diff);
void	print_spaces(t_stack *stack, int type, int max_stack);

//error handling:
//checking for error:
int		check_error(int n, char *argv[]);
//checking for argument errors:
int		check_argument_error(int n, char *argv[]);
int		check_for_duplicates(int *numbers, long cur_number, int cur_index);
int		check_if_num_is_in_int_range(long current_number, int *numbers);
int		check_if_num_is_digit(char *argv[], int *numbers, int cur_index);
//checking for errors in the stacks
int		check_stack_errors(t_stack **stack_a, t_stack **stack_b);

//sorting algorithm:
void	sorting_algorithm(t_stack **stack_a, t_stack **stack_b);
int		opration_calculations(t_stack *a, t_stack *b, int *cur_a, int *cur_b);
int		find_best_num(t_stack **stack_a, t_stack **stack_b, int num);
//short algorithm for nodes <= 5
int		short_algorithm(t_stack **stack_a, t_stack **stack_b, int count);
void	algorithm_three_nodes(t_stack **stack_a, int highest, int lowest);
//algorithm_helper_functions
int		ins_pos(t_stack *stack, int num);
int		calculate_op(t_stack *stack_a, t_stack *stack_b, int pos);
int		make_rotation(int *a, int *b, t_stack **stack_a, t_stack **stack_b);

//sorting functions:
//push:
int		push(t_stack **stack_1, t_stack **stack_2);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
//swap:
int		swap(t_stack **stack);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_ss(t_stack **stack_a, t_stack **stack_b);
//rotate:
int		rotate(t_stack **stack);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_rr(t_stack **stack_a, t_stack **stack_b);
int		reverse_rotate(t_stack **stack);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_rr(t_stack **stack_a, t_stack **stack_b);

//additional helper functions:
//helper functions 1:
int		stack_biggest_str_length(t_stack *stack);
int		stack_length(t_stack *stack);
long	ft_atou(const char *str);
int		*find_three_highest(t_stack *stack);
//helper functions 2:
int		find_highest(t_stack *stack);
int		find_lowest(t_stack *stack);
int		find_position(int num, t_stack *stack);
int		count_nodes(t_stack *stack);
int		lstlast(t_stack *stack);

#endif
