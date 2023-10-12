/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:51:19 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/11 22:42:08 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	counter;
	char			*char_dst;
	char			*char_src;

	counter = 0;
	char_dst = (char *)dst;
	char_src = (char *)src;
	while (counter < len)
	{
		char_dst[counter] = char_src[counter];
		counter++;
	}
	return (dst);
}

/* int	main (void)
{
	char dest[] = "oldstring";
	char dest2[] = "oldstring";
	const char src[]  = "newstring";

	memmove(dest, src, 2);
	printf("%s\n", dest);
	ft_memmove(dest2, src, 2);
	printf("%s\n", dest2);

	return(0);
} */
