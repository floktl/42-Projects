/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:12:23 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/13 12:24:59 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"

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
