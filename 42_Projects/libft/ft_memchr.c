/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:25:39 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/20 16:23:37 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//This function searches for the character in the first n bytes of the memory -
// area pointed to by s and returns a pointer to the matching byte
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
