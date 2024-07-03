/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:34:48 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 17:25:17 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "../libft.h"

/**
 * function to check if a character is in the ascii range
 *
 * @param c the character to check
 * @return 1 if char is ascii, 0 if not
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/* int main (void)
{
    int i;
    i = 0;
    i = ft_isascii(-1);
    printf("%d", i);
} */
