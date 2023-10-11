/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:26:24 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/06 16:39:32 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

int ft_strlen(char* c)
{
    int counter;

    counter = 0;
    while (*c != '\0')
    {
        counter++;
        c++;
    }
    return counter;
}

/* int main(void)
{
    int i;
    i = ft_strlen("");
    printf("%d", i);
} */