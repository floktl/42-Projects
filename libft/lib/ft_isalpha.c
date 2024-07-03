/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:10:56 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 17:24:51 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * function to check if a character is alphabetic
 *
 * @param c the character to check
 * @return 1 if char is alphabetic, 0 if not
 */
int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

/* int main (void)
{
    int i;
    i = 0;
    i = ft_isalpha((int)'a');
    printf("%d", i);
} */
