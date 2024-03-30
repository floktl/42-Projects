/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:51:19 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/27 14:19:03 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*((char *)(dst + i)) = *((char *)(src + i));
			i++;
		}
	}
	return (dst);
}

/*int	main (void)
{
	char dest1[] = "";
	char dest2[] = "";
	const char src[]  = "";

	memmove(dest1, src, 2);
	printf("%s\n", dest1);
	ft_memmove(dest2, src, 2);
	printf("%s\n", dest2);

	return(0);
}*/
