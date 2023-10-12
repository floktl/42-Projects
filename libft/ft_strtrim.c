/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:32:18 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/11 23:09:37 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trim;
	int		counter;
	int		counter_tr;
	int		counter_set;

	counter = 0;
	counter_tr = 0;
	counter_set = 0;
	str_trim = malloc(sizeof(s1));
	if (!s1)
		return (NULL);
	while (s1[counter] != '\0')
	{
		while (s1[counter] == set[counter_set])
		{
			counter++;
			if (set[counter_set + 1] != '\0')
				counter_set++;
		}
		if (s1[counter] != '\0')
		{
			str_trim[counter_tr] = s1[counter];
			counter_tr++;
			counter++;
		}
	}
	str_trim[counter_tr] = '\0';
	return (str_trim);
}

/* int main()
{
	char s1[] = "qqaqqqa";
	char set[] = "qqa";
	char* target = ft_strtrim(s1, set);
	printf("%s", target);
	free(target);
	return 0;
} */
