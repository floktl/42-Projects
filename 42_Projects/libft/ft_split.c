/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:08:31 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/20 16:33:38 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//
// This functions splits string by delimiter c into array of str's, return array
//

static int	count_words(const char *s, char c)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	j = 0;
	word = 0;
	while (s[j] != '\0')
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		while (s[j] != c && s[j] != '\0')
		{
			j++;
			word = 1;
		}
		if (word == 1)
			i += 1;
		word = 0;
	}
	return (i);
}

static char	*split_and_copy(const char *s, int *j, char c)
{
	int		word_count;
	int		x;
	int		word_start;
	char	*word;

	while (s[*j] == c && s[*j])
		(*j)++;
	if (s[*j])
	{
		word_start = *j;
		while (s[*j] && s[*j] != c && s[*j])
			(*j)++;
		if (word_start < *j)
		{
			word_count = *j - word_start;
			word = (char *)malloc(word_count + 1);
			x = 0;
			while (x < word_count)
				word[x++] = s[word_start++];
			word[x] = '\0';
			return (word);
		}
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		j;
	int		i;
	char	*word;

	i = 0;
	j = 0;
	arr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[j])
	{
		word = split_and_copy(s, &j, c);
		if (word)
			arr[i++] = word;
	}
	arr[i] = NULL;
	return (arr);
}
//#include <stdio.h>
//int main()
//{
//    const char *input_string = "hello!";
//    char delimiter = ' ';
//    char **result = ft_split(input_string, delimiter);
//    //if (result == NULL) {
//    //    printf("Memory allocation error\n");
//    //    return 1;
//    //}
//    //for (int i = 0; result[i] != NULL; i++) {
//    //    printf("Word %d: %s\n", i, result[i]);
//    //}
//    //for (int i = 0; result[i] != NULL; i++) {
//    //    free(result[i]);
//    //}
//    //free(result);
//    return 0;
//}
