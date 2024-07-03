/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:51:01 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 19:01:55 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * executes a function to each character of a string
 *
 * @param s the string to be executed
 * @param f the executive-function
 * @return the string after execution
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*int main()
{
	char *s = "Hellofghsjdf";
	char *str = ft_strmapi(s, &ft_tosupper);
	printf("%s\n", str);
	free(str);
	return (0);
}*/
