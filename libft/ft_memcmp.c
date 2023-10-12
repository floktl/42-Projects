/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:39:57 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/11 22:32:02 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter++ < n)
	{
		if (s1 < s2 || s1 > s2)
		{
			return (s1 - s2);
		}
	}
	return (0);
}

/* int main(void) {
    const char str1[] = "Hello, World!";
    const char str2[] = "Hello, Universe!";
    size_t compare_size = 7; // Number of characters to compare

    // Use memcmp to compare the first 'compare_size' characters of str1 and str2
    int result = ft_memcmp(str1, str2, compare_size);

    if (result == 0) {
        printf("The first %zu characters of str1 and str2 are equal.\n",
		compare_size);
    } else if (result < 0) {
        printf("The first %zu characters of str1 are less than str2.\n",
		compare_size);
    } else {
        printf("The first %zu characters of str1 are greater than str2.\n",
		compare_size);
    }

    return 0;
}
 */
