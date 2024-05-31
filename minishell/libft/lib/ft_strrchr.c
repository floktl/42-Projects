/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:44:28 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/25 14:11:21 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// char	*ft_strrchr(const char *s, int c)
// {
// 	int	counter;

// 	counter = 0;
// 	while (s[counter])
// 		counter++;
// 	while (counter >= 0)
// 	{
// 		if (s[counter] == (char)c)
// 			return ((char *)s + counter);
// 		counter--;
// 	}
// 	return (NULL);
// }

char	*ft_strchr(const char *s, int c)
{
	const char	*temp;

	temp = s;
	while (*temp != '\0')
	{
		if (*temp == (unsigned char)c)
			return ((char *)temp);
		temp++;
	}
	if (*temp == '\0' && (unsigned char)c == '\0')
		return ((char *)temp);
	else
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
