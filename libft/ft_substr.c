/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:15:31 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/11 23:05:19 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	int		counter;

	counter = 0;
	sub_str = (char *)malloc(len -(size_t) start);
	if ((char *)s == NULL || len == 0)
		return (NULL);
	while (len > 0)
	{
		sub_str[counter] = s[counter + start];
		len--;
		counter++;
	}
	sub_str[counter] = '\0';
	return (sub_str);
}

/* int main()
{
	char str[] = "dfhsdfsf";
	char* target = ft_substr(str, 1, 15);
	printf("%s", target);
	return 0;
} */
