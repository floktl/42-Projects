/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:44:28 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/27 14:20:32 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	counter;

	counter = 0;
	while (s[counter])
		counter++;
	while (counter >= 0)
	{
		if (s[counter] == (char)c)
			return ((char *)s + counter);
		counter--;
	}
	return (NULL);
}

/* int	main(void) {
	const char str[] = "bonjour";
	const char ch = 'b';
	char *ret;

	ret = ft_strrchr(str, ch);
	printf("String after %c is - %s\n", ch, ret);
	return 0;
}*/
