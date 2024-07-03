/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:39:57 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 17:45:23 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * compares byte string s1 against byte string s2 until the size n
 *
 * @param s1 the string
 * @param s2 the string to compare
 * @return the size difference of the first difference in the string
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
		{
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		}
		i++;
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
