/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:18:03 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 19:48:35 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//	this function allocates the new substring for the string replace in a string
int	alloc_string(char **s, int result_len)
{
	char	*temp;
	int		str_len;

	temp = NULL;
	str_len = (int)ft_strlen(*s);
	if (result_len >= str_len)
	{
		temp = (char *)malloc(sizeof(char) * (result_len + 1));
		if (!temp)
			return (EXIT_FAILURE);
		ft_memcpy(temp, *s, str_len);
		temp[str_len] = '\0';
		free(*s);
		*s = temp;
	}
	return (EXIT_SUCCESS);
}

/**
 * this function replaces in the str s the sub_str with the new_str
 *
 * @param s the string which will be edited
 * @param sub_str the sub_str which will be replaced by new_str
 * @param new_str the new_string, which will be replace the sub_str in the
 * string s
 * @param position the position of the sub_str in string s
 * @return 1 if substring is replaced, 0 if there is no substr,
 * -1 if error occurs
 */
int	replace_substr(char **s, char **sub_str, char *new_str, int position)
{
	char	*substr_pos;
	int		rep_len;
	int		len_new_st;

	if (!(*sub_str) || !(*s))
		return (0);
	rep_len = ft_strlen(*sub_str);
	free(*sub_str);
	len_new_st = ft_strlen(new_str);
	if (alloc_string(s, ft_strlen(*s) - rep_len + len_new_st) == EXIT_FAILURE)
	{
		free(new_str);
		return (-1);
	}
	substr_pos = *s + position;
	if (!substr_pos || substr_pos < *s)
		return (0);
	ft_memmove(substr_pos + len_new_st, substr_pos + rep_len,
		ft_strlen(substr_pos + rep_len) + 1);
	ft_memcpy(substr_pos, new_str, len_new_st);
	free(new_str);
	if (alloc_string(s, ft_strlen(*s)) == EXIT_FAILURE)
		return (-1);
	return (1);
}

//#include <string.h>

//int	main(void)
//{
//	char *s = strdup("Hello this is a temporary and strong test!");
//	char *sub_str = strdup("temporary and strong");
//	char *new_str = strdup("easy");
//	int i = 15;
//	replace_substr(&s, &sub_str, new_str, &i);
//	free(s);
//	printf("%s\n", s);
//	printf("%d", i);
//}
