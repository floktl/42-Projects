/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:01:59 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 19:51:12 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	free_str(char *s1, char *s2, int num)
{
	if (num == 1 || num == 0)
		free(s1);
	if (num == 2 || num == 0)
		free(s2);
}

//	strjoin function, which frees the second string s2
/**
 * joins both strings s1 and s2 together and frees the strings
 * dependent of the value of num
 *
 * @param s1 the first string
 * @param s1 the string to be added at the end of s1
 * @param num if 0, both str will be freed, 1 the first, 2 the second only
 * @return the joined string
 */
char	*strjoin_free(char *s1, char *s2, int num)
{
	char	*conc_str;
	int		counter;
	int		counter_2;

	counter = 0;
	counter_2 = 0;
	if (!s1 || !s2)
		return (NULL);
	conc_str = malloc((int)ft_strlen(s1) + (int)ft_strlen(s2) + 1);
	if (conc_str == NULL)
		return (NULL);
	while (s1[counter] != '\0')
	{
		conc_str[counter] = s1[counter];
		counter++;
	}
	while (s2[counter_2] != '\0')
	{
		conc_str[counter_2 + counter] = s2[counter_2];
		counter_2++;
	}
	conc_str[counter + counter_2] = '\0';
	free_str(s1, s2, num);
	return (conc_str);
}
