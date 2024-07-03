/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:00:03 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 18:39:21 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * copy and concatenate both strings dst and src
 *
 * @param dst the first string
 * @param src the string to be added at the end of s1
 * @param dstsize the size of the destination string
 * @return the size of the new string
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	size_t	dest_len;

	counter = 0;
	dest_len = 0;
	while (dst[dest_len] != '\0' && dest_len < dstsize)
		dest_len++;
	counter = dest_len;
	while (*src != '\0' && counter + 1 < dstsize)
		dst[counter++] = *src++;
	if (counter < dstsize)
		dst[counter] = '\0';
	while (*src != '\0')
	{
		counter++;
		src++;
	}
	return (counter);
}

// #include <string.h>
// #include <stdio.h>
// int main() {
// 	char destination[20] = "Hello, ";
// 	const char* source = "how are you";
// 	size_t result = strlcat(destination, source, sizeof(destination));
// 	printf("Result: %zu\n", result);
// 	printf("Concatenated String: %s\n", destination);
// 	return 0;
// }
