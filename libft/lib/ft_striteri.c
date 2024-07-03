/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:51:14 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 18:24:37 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * executes the function f for each character in the string s
 *
 * @param s the string to execute the operations
 * @param f the execute-function
 */
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
