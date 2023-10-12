/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:55:20 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/11 22:52:59 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;

	counter = 0;
	while (*src != '\0' && counter < dstsize)
	{
		dst[counter] = *src;
		src++;
		counter++;
	}
	return (counter);
}

/* int main() {
	char destination[20];  // Define a destination buffer
	const char* source = "Hello, World!";  // Source string
	size_t copied = ft_strlcpy(destination, source, sizeof(destination));
	printf("Copied %zu characters\n", copied);
	printf("Destination: %s\n", destination);
	return 0;
} */
