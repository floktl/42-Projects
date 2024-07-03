/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:34:48 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 17:26:02 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "../libft.h"

/**
 * function to check if a character is a printable character
 *
 * @param c the character to check
 * @return 1 if char is printable, 0 if not
 */
int	ft_isprint(int c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}

/* int main (void)
{
    int i;
    i = 0;
    i = ft_print(-1);
    printf("%d", i);
} */
