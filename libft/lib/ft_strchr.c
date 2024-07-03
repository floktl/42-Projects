/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:03:40 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 18:19:42 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * locates the first occurrence of c (converted to a char)
 * in the string pointed to by s
 *
 * @param s the string in which to search for
 * @param c the character to search
 * @return the pointer at the first occurance
 */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && (unsigned char)c == '\0')
		return ((char *)&s[i]);
	else
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
