/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:34:32 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 18:03:21 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * writes a string followed by a newline to the given file descriptor
 *
 * @param s the string to write
 * @param fd the file descriptor
 */
void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

/*main ()
{
	char *s = "Hellofghsjdf";
	ft_putendl_fd(s, 1);
	return (0);
}*/
