/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:13:06 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/31 09:29:35 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	char	*temp_s3;
	size_t	s1_length;
	size_t	s2_length;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	s3 = (char *)ft_calloc(1, (s1_length + s2_length) + 1);
	if (!s3)
		return (NULL);
	temp_s3 = s3;
	while (*s1)
		*s3++ = *s1++;
	while (*s2)
		*s3++ = *s2++;
	return (temp_s3);
}

/* int main()
{
	char str1[] = "lorem ipsum";
	char str2[] = "dolor sit amet";
	char* target = ft_strjoin(str1, str2);
	printf("%s", target);
	return 0;
}*/
