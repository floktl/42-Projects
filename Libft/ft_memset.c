/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:48:03 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/11 17:17:37 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len) //str: pointer to the block, c: value to be set, n = numbers of bytes
{
	size_t counter;
	counter = 0;

	char *char_b = (char *)b;
	while (*char_b != '\0' && counter <= len -1)
	{
		char_b[counter++] = c;
	}
	return b;
}

int	main(void)
{
	char c[] = "fjfcfh";
	ft_memset(c, '!', 2);
	printf("%s\n", c);
}
