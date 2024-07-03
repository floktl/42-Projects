/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:15:55 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 17:25:41 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * function to check if a character is a digit from 0 to 9
 *
 * @param c the character to check
 * @return 1 if char is a digit, 0 if not
 */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/* int main (void)
{
    int i;
    i = 0;
    i = ft_isdigit('a');
    printf("%d", i);
}  */
