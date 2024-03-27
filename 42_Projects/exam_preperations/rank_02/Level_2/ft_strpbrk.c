/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:53:29 by flo               #+#    #+#             */
/*   Updated: 2024/01/23 16:28:13 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j;
	char *dst;

	i = 0;
	j = 0;
	while (s2[j])
	{
		i = 0;
		while (s1[i])
		{
			if (s1[i] == s2[j])
			{
				dst = (char *)s2[j];
				return (dst);
			}
			i++;
		}
		j++;
	}
	return (NULL);
}

int	main(void)
{
	const char	*s1 = "ksjvsku";
	const char	*s2 = "ju";

	printf("%s", ft_strpbrk(s1, s2));
	return (0);
}
