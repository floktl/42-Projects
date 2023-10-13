/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:18:52 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/13 11:00:30 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	counter;

	counter = 0;
	s2 = (char *) malloc((size_t) sizeof(*s1) + 1);
	if (!s2)
		return (NULL);
	while (s1[counter] != '\0')
	{
		s2[counter] = s1[counter];
		counter++;
	}
	s2[counter] = '\0';
	return (s2);
}

/*int main()
{
	char source[] = "dfh";
	char* target = ft_strdup(source);
	printf("%s", target);
	free(target);
	return 0;
}*/
