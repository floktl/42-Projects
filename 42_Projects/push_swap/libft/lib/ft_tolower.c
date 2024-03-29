/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:50:44 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/27 14:20:43 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/* int	main (void)
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
} */
