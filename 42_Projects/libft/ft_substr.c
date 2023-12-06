/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:15:31 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/18 16:51:13 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_calloc(1, 1));
	if (len > s_len - start)
		len = s_len - start;
	sub_str = (char *)malloc(len + 1);
	if (sub_str == NULL)
		return (NULL);
	while (i < len && s[i + start] != '\0')
	{
		sub_str[i] = s[i + start];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

/* int main()
{
	char str[] = "lorem ipsum dolor sit amet";
	char* target = ft_substr(str, 7, 10);
	printf("%s\n", target);
	free(target);
	return 0;
}*/
