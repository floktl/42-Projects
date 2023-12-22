/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:26:24 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/20 16:39:31 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

//This function calculates and returns the length of the string c
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
