/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:26:24 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 18:59:52 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * returns the string length of c
 *
 * @param c the string
 * @return the size of the string length until the null terminator
 */
size_t	ft_strlen(const char *c)
{
	size_t	counter;

	counter = 0;
	while (*c != '\0')
	{
		counter++;
		c++;
	}
	return (counter);
}

/* int main(void)
{
    int i;
    i = ft_strlen("");
    printf("%d", i);
} */
