/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:03:40 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/27 14:19:55 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	str_len;

	str_len = ft_strlen(s);
	while (str_len >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		str_len--;
	}
	return (NULL);
}

/*  int main (void)
{
   const char str[] = "https://www.tutorialspoint.com";
   char *ret;
   char *ret2;

   ret = ft_strchr(str, 't' + 256);
   ret2 = strchr(str, 't' + 256);
   printf("%s\n", ret);
   printf("%s\n", ret2);
   return(0);
}*/
