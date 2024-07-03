/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:25:39 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 17:42:58 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * locates the first occurrence of c (converted to an unsigned char) in string s
 *
 * @param s the string to search in
 * @param c the character to find
 * @return the pointer of the first occurance
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*z;
	unsigned char		uc;
	size_t				counter;

	uc = (unsigned char)c;
	z = (const unsigned char *)s;
	counter = 0;
	while (counter++ < n)
	{
		if (*z == uc)
			return ((void *)z);
		z++;
	}
	return (0);
}

/* int	main(void) {
	const char str[] = "/|\x12\xff\x09\x42\2002\42|\\";
	char search_char = '\200';
	size_t search_size = 10;
	const void *result = ft_memchr(str, search_char, search_size);
	size_t index = (size_t)((const char *)result - str);
	printf("'%c' found at index %zu\n", search_char, index);
	return 0;
}*/
