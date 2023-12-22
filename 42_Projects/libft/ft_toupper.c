/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:12:23 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/20 17:03:57 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Convert an lowercase character to uppercase if applicable.
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/* int	main (void)
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
} */
