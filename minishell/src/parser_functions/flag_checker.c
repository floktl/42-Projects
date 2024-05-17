/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:41:54 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/28 16:43:20 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//int	count_flags(const char *str, int start, char c)
//{
//	int	count;
//	int	i;

//	count = 0;
//	i = start;
//	while (str[i])
//	{
//		if (str[i] == c)
//		{
//			count++;
//		}
//		i++;
//	}
//	return (count);
//}

////	check if there are any flags in the command string save them in struct
//int	check_for_flag(t_tree *tree, char *cmd_str, int start)
//{
//	int		i;
//	char	**flags;
//	int		flag_num;
//	int		fl_l;
//	int		fl_c;

//	i = start;
//	fl_c = 0;
//	flags = NULL;
//	flag_num = count_flags(cmd_str, start, '-');
//	if (flag_num > 0)
//	{
//		flags = (char **)malloc(sizeof(char *) * (flag_num + 1));
//		if (!flags)
//		{
//			free_two_dimensional_array(flags);
//			perror("malloc");
//			return (EXIT_FAILURE);
//		}
//		flags[flag_num] = NULL;
//		flags[0] = (char *)malloc((sizeof(char)) * 2);
//		while (cmd_str[i] && flag_num > 0)
//		{
//			while (cmd_str[i] && cmd_str[i] == ' ')
//				i++;
//			if (cmd_str[i] && cmd_str[i - 1] == ' ' && cmd_str[i] == '-')
//			{
//				flags[fl_c][0] = '-';
//				flags[fl_c][1] = '\0';
//				fl_l = 1;
//				i++;
//				while (cmd_str[i] && cmd_str[i] != ' ' && cmd_str[i] != '\n')
//				{
//					flags[fl_c] = (char *)realloc(flags[fl_c],
//							(sizeof(char)) * (fl_l + 2));
//					if (!flags[fl_c])
//					{
//						free_two_dimensional_array(flags);
//						perror("malloc");
//						return (EXIT_FAILURE);
//					}
//					flags[fl_c][fl_l++] = cmd_str[i];
//					i++;
//				}
//				flags[fl_c][fl_l] = '\0';
//				fl_c++;
//				flag_num--;
//			}
//			else
//				i++;
//		}
//	}
//	tree->flags = flags;
//	return (EXIT_SUCCESS);
//}
