/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:50:22 by flo               #+#    #+#             */
/*   Updated: 2024/06/28 18:09:20 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * function to reallocate memory to an existing datatype
 *
 * @param ptr the string to reallocate
 * @param size the new size
 * @param size the new size
 * @return the reallocated string
 */
void	*ft_realloc(void *ptr, size_t size)
{
	void	**new_ptr;

	new_ptr = NULL;
	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, sizeof(void *));
	free(ptr);
	return (new_ptr);
}
