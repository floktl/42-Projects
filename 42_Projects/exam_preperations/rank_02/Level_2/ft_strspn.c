/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:40:54 by flo               #+#    #+#             */
/*   Updated: 2024/01/24 20:03:19 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	n;
	int		i;

	n = 0;
	i = 0;
	while (s[i] == accept[i])
	{
		n++;
		i++;
	}
	return (n);
}

int	main(void)
{
	int			len;
	const char	str1[] = "ABCEFG019874";
	const char	str2[] = "BBCF";

	len = ft_strspn(str1, str2);
	printf("Length of initial segment matching %d\n", len);
	return (0);
}
