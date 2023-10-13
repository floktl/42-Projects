/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:48:03 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/13 14:20:06 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

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
