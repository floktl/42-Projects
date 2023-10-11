/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:12:23 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/07 17:59:16 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <ctype.h>
 #include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'b')
	{
		c -= 32;
	}
	return c;
}

int	main (void)
{
	char ch;
	char sh;

	sh = 'a';
    ch = 'b';
	char y = ft_toupper(sh);
	printf("%c in uppercase is represented as%c", sh, y);
	char x = toupper(ch);
	
    printf("%c in uppercase is represented as%c", ch, x);
	return 0;
}