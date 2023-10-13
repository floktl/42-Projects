/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:51:19 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/13 15:12:31 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	counter;
	char			*char_dst;
	char			*char_src;

	counter = 0;
	char_dst = (char *)dst;
	char_src = (char *)src;
	if (char_dst == NULL && char_src == NULL)
		return (NULL);
	if (char_dst == char_src)
		return (dst);
	while (counter < len)
	{
		char_dst[counter] = char_src[counter];
		counter++;
	}
	dst = char_dst;
	return (dst);
}

 int	main (void)
{
	char dest1[] = "111111111111111111";
	char dest2[] = "111111111111111111";
	const char src[]  = "newstringfhjfghfcbgdf";

	memmove(dest1, src, 2);
	printf("%s\n", dest1);
	ft_memmove(dest2, src, 2);
	printf("%s\n", dest2);

	return(0);
}
