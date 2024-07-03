/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_term_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:59:46 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 19:37:24 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * 	Function to create an empty string, returning EXIT_FAILURE if error occurs
 *
 * @param str the string
 * @return 1 if the allocation went wrong, 0 if not
 */
int	null_term_string(char **str)
{
	if (!(*str))
	{
		*str = malloc(sizeof(char));
		if (!(*str))
			return (1);
		(*str)[0] = '\0';
	}
	return (0);
}
