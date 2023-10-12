/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:25:39 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/11 22:30:32 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*z;
	size_t				counter;

	z = (const unsigned char *)s;
	counter = 0;
	while (counter++ < n)
	{
		if (*z == c)
			return ((void *)z);
		z++;
	}
	return (0);
}

/* int	main(void) {
	const char str[] = "Hello, World!";
	char search_char = 'o';
	size_t search_size = 5;
	const void *result = ft_memchr(str, search_char, search_size);
	size_t index = (size_t)((const char *)result - str);
	printf("'%c' found at index %zu\n", search_char, index);
	return 0;
}
 */
