/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:48:03 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/11 22:43:44 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	counter;
	char	*char_b;

	counter = 0;
	char_b = (char *)b;
	while (*char_b != '\0' && counter <= len -1)
	{
		char_b[counter++] = c;
	}
	return (b);
}

/* int	main(void)
{
	char c[] = "fjfcfh";
	ft_memset(c, '!', 2);
	printf("%s\n", c);
} */
