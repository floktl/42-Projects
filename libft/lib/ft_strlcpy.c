/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:55:20 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 18:58:48 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * copy the str src to dst until size dstsize
 *
 * @param dst the first string
 * @param src the string to be copied
 * @param dstsize the size of the destination string
 * @return the size of the new string
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;

	counter = 0;
	if (dstsize > 0)
	{
		while (src[counter] != '\0' && counter < dstsize - 1)
		{
			dst[counter] = src[counter];
			counter++;
		}
		dst[counter] = '\0';
	}
	while (src[counter] != '\0')
		counter++;
	return (counter);
}

/* int main() {
	char destination[20];  // Define a destination buffer
	const char* source = "Hello, World!";  // Source string
	size_t copied = ft_strlcpy(destination, source, sizeof(destination));
	printf("Copied %zu characters\n", copied);
	printf("Destination: %s\n", destination);
	return 0;
}*/
