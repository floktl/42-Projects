/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:13:06 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/10 13:30:48 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*conc_str;
	int counter;
	int counter_2;

	counter = 0;
	counter_2 = 0;
	conc_str = malloc(sizeof(s1) + sizeof(s2));
	if (!s1 || !s2)
		return NULL;
	while (s1[counter] != '\0')
	{
		conc_str[counter] = s1[counter];
		counter++;
	}
	while (s1[counter] == '\0' && s2[counter_2] != '\0')
		{
			conc_str[counter_2 + counter] = s2[counter_2];
			counter_2++;
		}
	conc_str[counter + counter_2] = '\0';
	return (conc_str);
}

int main()
{
	char str1[] = "";
	char str2[] = "aaaaa";
	char* target = ft_strjoin(str1, str2);
	printf("%s", target);
	return 0;
}
