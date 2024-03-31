/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:57:56 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/30 09:33:56 by flo              ###   ########.fr       */
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

//	create:
int		initstack(t_list **stack, int argc, char **argv);
int		main(int argc, char *argv[]);

//	print_stacks
void	print_spaces(t_list *stack, int type, int max_stack);
int		print_one_node(t_list **stack, int max_length, int diff);
void	print_spaces_in_between(t_list **b, int *diff, int len_a, int len_b);
int		printing_nodes(t_list *temp_a, t_list *temp_b, int len_a, int len_b);
void	print_stacks(t_list *stack_a, t_list *stack_b);

//	error_handling:
//finding error type:
int		check_error(char **args);
//argument_errors:
int		check_arg(char **argv);
int		check_for_duplicates(char **args, long cur_number);
int		check_if_num_is_in_int_range(long current_number);
int		check_if_num_is_digit(char **args, int cur_index);
//stack_errors
int		check_stack_errors(t_list **stack_a, t_list **stack_b);

//	sorting_algorithm
//algorithm:
int		ret_best(int a, int b, int cur_num, int *lowest_operations);
int		find_low_op(int rot_a, int rot_b, int cur_num, int *best);
int		op_calc(t_list *a, t_list *b, int *cur_a, int *cur_b);
int		prepare_and_push(t_list **a, t_list **b, int rot_a, int rot_b);
void	sorting_algorithm(t_list **stack_a, t_list **stack_b);
//short_algorithm
void	algorithm_three_nodes(t_list **stack_a, int highest, int lowest);
int		short_algorithm(t_list **stack_a, int count);
//algorithm_help_functions
int		find_last_element(t_list *stack);
int		ins_pos(t_list *stack, int num);
int		calculate_op(t_list *stack, int pos);
int		rotate_both(int *a, int *b, t_list **stack_a, t_list **stack_b);
void	rot_highest_to_top(t_list **stack_b);

//	sorting functions:
//push:
int		push(t_list **stack_1, t_list **stack_2);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
//swap:
int		swap(t_list **stack);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_ss(t_list **stack_a, t_list **stack_b);
//rotate:
int		rotate(t_list **stack);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_rr(t_list **stack_a, t_list **stack_b);
//reverse_rotate
int		reverse_rotate(t_list **stack);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_rr(t_list **stack_a, t_list **stack_b);

//	additional helper functions:
//helper functions 1:
int		*find_three_highest(t_list *stack);
void	check_which_highest(int **highest, int value);
int		stack_biggest_str_length(t_list *stack);
int		stack_length(t_list *stack);
long	ft_atou(const char *str);
//helper functions 2:
int		find_highest(t_list *stack);
int		find_lowest(t_list *stack);
int		find_position(int num, t_list *stack);
int		count_nodes(t_list *stack);
int		check_if_sorted(t_list *stack);
//helper_functions 3:
void	ft_free(char **str);
void	free_stack(t_list **stack);

#endif
