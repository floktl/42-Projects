/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_substr_first_word.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:09:44 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 19:35:31 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//#include <stdio.h>
//#include <string.h>

//  function to compare if two strings are the same, independent upper/lower
int	word_cmp(const char *s1, const char *s2, size_t n, int st)
{
	size_t	counter;
	char	c1;
	char	c2;

	counter = 0;
	c1 = 0;
	c2 = 0;
	while ((*s1 != '\0' || *s2 != '\0') && counter < n)
	{
		c1 = *s1;
		c2 = *s2;
		if (st == 1)
		{
			if (c1 >= 'A' && c1 <= 'Z')
				c1 += ('a' - 'A');
			if (c2 >= 'A' && c2 <= 'Z')
				c2 += ('a' - 'A');
		}
		if (c1 != c2)
			return ((int)((unsigned char)*s1 - (unsigned char)*s2));
		s1++;
		s2++;
		counter++;
	}
	return (0);
}

/**
 * function to check if the substring is the first word in a string
 *
 * @param str the string to search for
 * @param sub_str the sub string to search for in str
 * @param st start of the search
 * @return 1 if sub_str is the first word, 0 if not
 */
int	is_substr_first_word(const char *str, const char *sub_str, int st)
{
	size_t	sub_str_len;
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	sub_str_len = ft_strlen(sub_str);
	if (sub_str_len == 0 || sub_str_len > ft_strlen(str + i))
	{
		return (0);
	}
	if (word_cmp(str + i, sub_str, sub_str_len, st) == 0)
	{
		if (str[sub_str_len + i] == ' ' || str[sub_str_len + i] == '\0')
		{
			return (1);
		}
	}
	return (0);
}

//int main() {
//    // Example usage
//    char str[] = "echo ;fi ifviub fuvh | ";
//    char sub_str[] = "hello";

//    if (is_substr_first_word(str, sub_str)) {
//        printf("%s is the first word of %s\n", sub_str, str);
//    } else {
//        printf("%s is not the first word of %s\n", sub_str, str);
//    }

//    return 0;
//}
