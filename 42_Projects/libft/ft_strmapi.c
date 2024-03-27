/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:51:01 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/20 17:07:52 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//This function creat new string by applying function f to each character of str
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

//int main()
//{
//	char *s = "Hellofghsjdf";
//	char *str = ft_strmapi(s, &ft_tosupper);
//	printf("%s\n", str);
//	free(str);
//	return (0);
//}
