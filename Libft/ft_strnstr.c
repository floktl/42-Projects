/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:11:47 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/08 18:57:34 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t counter;
	int str_count;

	counter = 0;
	str_count = 0;
	while (*haystack && counter++ < len)
	{
		const char *temp_haystack;
		temp_haystack =  haystack;
		while (*temp_haystack == *needle)
		{
			str_count = 1;
			temp_haystack++;
			needle++;
		}
		if (str_count == 1)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}

int main() {
    const char* haystack = "This is a test string for strnstr function.";
    const char* needle = "is a test";
    size_t len = strlen(haystack);

    char* result = ft_strnstr(haystack, needle, len);

    if (result) {
        printf("Needle found at position: %ld\n", result - haystack);
        printf("Substring: %s\n", result);
    } else {
        printf("Needle not found.\n");
    }

    return 0;
}

