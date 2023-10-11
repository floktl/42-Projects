/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:50:44 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/07 18:01:16 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <ctype.h>
 #include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
	}
	return c;
}

int	main (void)
{
	char ch;
	char sh;

	sh = 'A';
    ch = 'B';
	char y = ft_toupper(sh);
	printf("%c in undercase is represented as%c", sh, y);
	char x = tolower(ch);
	
    printf("%c in undercase is represented as%c", ch, x);
	return 0;
}