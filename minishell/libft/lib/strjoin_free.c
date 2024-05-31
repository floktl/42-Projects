/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:01:59 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/30 11:37:56 by stopp            ###   ########.fr       */
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
