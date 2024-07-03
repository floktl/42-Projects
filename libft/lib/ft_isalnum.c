/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:10:56 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 17:24:26 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * function to check if a character is alphanumeric
 *
 * @param c the character to check
 * @return 1 if char is alphanum, 0 if not
 */
int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57))
		return (1);
	return (0);
}

/* int main (void)
{
    int i;
    i = 0;
    i = ft_isalnum(' ');
    printf("%d", i);
} */
