/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_two_dimensional_array.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:57:41 by flo               #+#    #+#             */
/*   Updated: 2024/06/28 17:14:11 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * function to free an two dimensional array of chars
 *
 * @param bits the two dimensional array to free
 */
void	free_two_dimensional_array(char **param)
{
	int	count;

	count = 0;
	if (!param)
		return ;
	while (param[count])
	{
		free(param[count]);
		param[count] = NULL;
		count++;
	}
	free(param);
	param = NULL;
}
