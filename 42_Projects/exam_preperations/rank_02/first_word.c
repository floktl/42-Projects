/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:14:51 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/19 16:41:48 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (!argv[1] && argv[1])
		return (-1);
	if (argc == 2)
	{
		while (argv[1][i] == ' ' && argv[1][i] != '\n' && argv[1][i] == '\t')
			i++;
		while (argv[1][i] != ' ' && argv[1][i] && argv[1][i] != '\t')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
