/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:32:18 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 19:19:30 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * returns trimmed string s1 by the substr set at the first occurance
 *
 * @param s1 string to trim
 * @param set trimmer
 * @return trimmed string, NULL if set is not found
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trim;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	str_trim = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!str_trim)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		str_trim[i] = s1[start];
		i++;
		str_trim[i] = '\0';
		start++;
	}
	return (str_trim);
}

#include <stdio.h>
int main()
{
	char s1[] = "qqaqqqa";
	char set[] = "qqa";
	char* target = ft_strtrim(s1, set);
	printf("%s", target);
	free(target);
	return 0;
}
