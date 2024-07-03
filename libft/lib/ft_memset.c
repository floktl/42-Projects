/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:48:03 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 18:00:21 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * writes len bytes of value c (converted to an unsigned char) to the string b
 *
 * @param b the string to insert in
 * @param c the character to write
 * @param len the size to write
 * @return the pointer to the new string
 */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	counter;
	char	*char_b;

	counter = 0;
	char_b = (char *)b;
	if (len == 0)
		return (b);
	while (counter <= len - 1)
	{
		char_b[counter++] = c;
	}
	b = char_b;
	return (b);
}

/*#include <stdio.h>
#include <string.h>

int main () {
   char str[50];

   strcpy(str,"");
   puts(str);

   ft_memset(str,'$',0);
   puts(str);

   return(0);
}*/
