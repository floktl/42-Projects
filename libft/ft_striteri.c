/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:51:14 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/13 10:39:58 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	ft_strlen(const char *c)
{
	int	counter;

	counter = 0;
	while (*c != '\0')
	{
		counter++;
		c++;
	}
	return (counter);
}

void	ft_tosupper(unsigned int index, char *c)
{
	index = 0;
	if (*c >= 'a' && *c <= 'z')
		*c = (char)(*c - 32);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*int main()
{
	char s[] = "Hellofghsjdf";
	ft_striteri(s, &ft_tosupper);
	printf("%s\n", s);
	return (0);
}*/
