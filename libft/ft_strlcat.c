/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:00:03 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/13 10:40:05 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	counter_dst;
	size_t	counter_src;
	size_t	space_left;

	counter_dst = 0;
	counter_src = 0;
	while (dst[counter_dst] != '\0')
		counter_dst++;
	space_left = dstsize - counter_dst;
	while (*src != '\0' && space_left-- > 1)
		dst[counter_dst++] = *src++;
	dst[counter_dst] = '\0';
	while (*src++ != '\0')
		counter_src++;
	return (counter_dst + counter_src);
}

/* int main() {
	char destination[20] = "Hello, ";
	const char* source = "";
	size_t result = strlcat(destination, source, sizeof(destination));
	printf("Result: %zu\n", result);
	printf("Concatenated String: %s\n", destination);
	return 0;
}
 */
