/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:41:54 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/19 00:02:07 by flo              ###   ########.fr       */
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

//int	search_for_variable_in_env(char *variable, char **envp)
//{
//	char	*replace;
//	int		i;
//	int		j;
//	int		temp;

//	i = 0;
//	while (envp[i])
//	{
//		j = 1;
//		while (envp[i][j] && variable[i] && envp[i][j + 1] == variable[1])
//		{
//			j++;
//		}
//		if (envp[i][j] && envp[i][j + 1] &&  envp[i][j] == '=')
//		{
//			j++;
//			j = temp;
//			while (envp[i][temp])
//			{
//				temp++;
//			}
//			free(variable);
//			variable = ft_substr(envp[i], j, temp - 1);
//			return (0);
//		}
//	}
//	return (1);
//}

//int main() {
//    // Allocate memory for the environment variables array
//    char **envp = (char **)malloc(7 * sizeof(char *));
//    if (envp == NULL) {
//        perror("Memory allocation failed");
//        return 1;
//    }

//    // Set environment variables
//    envp[0] = strdup("HOSTNAME=e3d678c4e42d");
//    envp[1] = strdup("PWD=/dorker_workspace/miniiii/minishell");
//    envp[2] = strdup("HOME=/root");
//    envp[3] = strdup("TERM=xterm");
//    envp[4] = strdup("SHLVL=1");
//    envp[5] = strdup("PATH=/usr/local/sbin:/usr/l=");
//    envp[6] = strdup("OLDPWD=/dorker_workspace/miniiii");

//    // Test the search_for_variable_in_env function
//    char *variable = strdup("PWD");
//    int result = search_for_variable_in_env(variable, envp);
//    if (result == 0) {
//        printf("Variable found: %s\n", variable);
//    } else {
//        printf("Variable not found\n");
//    }

//    // Free allocated memory
//    for (int i = 0; i < 7; i++) {
//        free(envp[i]);
//    }
//    free(envp);

//    free(variable); // Don't forget to free the variable allocated by strdup

//    return 0;
//}
