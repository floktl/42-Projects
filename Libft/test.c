/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:45:19 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/10 20:02:55 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		trimmed_length;
	char	*str_trim;
	int		i;

	start = 0;
	i = 0;
	end = sizeof(s1) - 1;
	while (s1[start] != '\0' && is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end], set))
		end--;
	trimmed_length = (end - start + 1);
	str_trim = (char *)malloc(trimmed_length + 1);
	if (str_trim == NULL)
		return (NULL);
	while (i < trimmed_length)
	{
		str_trim[i] = s1[start + i];
		i++;
	}
	str_trim[trimmed_length] = '\0';
	return (str_trim);
}

int	main() {
	char s1[] = "qqabqqa";
	char set[] = "qqa";
	char *target = ft_strtrim(s1, set);
	printf("%s\n", target);
	free(target);
	return (0);
}
