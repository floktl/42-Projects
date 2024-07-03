/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:15:31 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 19:24:38 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * returns a substring out of string s, starting at start with the length len
 *
 * @param s strin
 * @param start start of
 * @return trimmed string
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	char	*temp_sub_s;
	size_t	count;
	size_t	count_sub;
	size_t	size_s;

	size_s = ft_strlen(s);
	if (len > size_s)
		len = size_s;
	sub_s = (char *)ft_calloc(len + 1, sizeof(char));
	if (!sub_s)
		return (NULL);
	count_sub = 0;
	count = 0;
	temp_sub_s = sub_s;
	while (s[count] && count_sub < len)
	{
		if (count >= start)
		{
			*sub_s++ = s[count];
			count_sub++;
		}
		count++;
	}
	return (temp_sub_s);
}

/* int main()
{
	char str[] = "lorem ipsum dolor sit amet";
	char* target = ft_substr(str, 7, 10);
	printf("%s\n", target);
	free(target);
	return 0;
}*/
