/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_term_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:59:46 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/29 10:00:28 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//	Function to create an empty string, returning EXIT_FAILURE if error occurs
int	null_term_string(char **command_str)
{
	if (!(*command_str))
	{
		*command_str = malloc(sizeof(char));
		if (!(*command_str))
			return (EXIT_FAILURE);
		(*command_str)[0] = '\0';
	}
	return (EXIT_SUCCESS);
}
