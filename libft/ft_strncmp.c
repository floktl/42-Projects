/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:39:10 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/13 10:40:23 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	while ((*s1 != '\0' || *s2 != '\0') && counter++ < n)
	{
		if (*s1 < *s2 || *s1 > *s2)
			return ((int)(*s1 - *s2));
		s1++;
		s2++;
	}
	return (0);
}

/* int	main(void)
{
	const char str[] = "19345399";
	const char str2[] = "9234547";
	int i = 0;
	int j = 0;
	i = strncmp(str, str2, 5);
	printf("%d", i);
	j = ft_strncmp(str, str2, 5);
	printf("%d", j);
} */
