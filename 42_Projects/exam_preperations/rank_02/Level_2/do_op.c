/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:20:57 by flo               #+#    #+#             */
/*   Updated: 2024/01/23 15:36:46 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	one;
	int	two;

	if (argc == 4)
	{
		one = atoi(argv[1]);
		two = atoi(argv[3]);
		if (argv[2][0] == '*')
			printf("%d", one * two);
		else if (argv[2][0] == '/')
			printf("%d", one / two);
		else if (argv[2][0] == '-')
			printf("%d", one - two);
		else if (argv[2][0] == '+')
			printf("%d", one + two);
		else	return (-1);
	}
	printf("\n");
	return (0);
}
