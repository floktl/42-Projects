/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:34:48 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/06 15:52:45 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

int ft_isascii(char c)
{
    if (c >= 0 && c <= 127)
    {
        return 1;
    }
    else{
        return 0;
    }
}

/* int main (void)
{
    int i;
    i = 0;
    i = ft_isascii(-1);
    printf("%d", i);
} */