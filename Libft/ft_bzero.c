/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:18:51 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/11 17:17:10 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void *ft_bzero(void *s, size_t n)
{
    size_t counter;
    counter = 0;

    char *char_s = (char *)s;
    while (counter <= n -1)
    {
        char_s[counter++] = '\0';
    }
    return s;
}

int main(void)
{
    char c[] = "asdgs";
    ft_bzero(c, 3); // Use bzero to set the first 3 bytes to null (0)
    printf("%s\n", c);
    return (0);
}
