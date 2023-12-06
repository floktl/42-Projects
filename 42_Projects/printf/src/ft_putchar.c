/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:26:24 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/24 09:32:59 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c, int fd, int counter)
{
	int	check;

	check = write(fd, &c, counter);
	if (check == -1)
		return (-1);
	return (1);
}
