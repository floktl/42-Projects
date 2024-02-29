/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blah.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:34:50 by fkeitel           #+#    #+#             */
/*   Updated: 2024/02/27 13:39:28 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <math.h>

int round_to_int(float num) {
    if (num >= 0) {
        return (int)(num + 0.5);
    } else {
        return (int)(num - 0.5);
    }
}

int	main(void)
{
	printf("%d", round_to_int(3.654));
	return (0);
}
