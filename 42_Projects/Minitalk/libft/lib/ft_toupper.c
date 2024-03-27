/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:12:23 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/27 14:20:47 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
