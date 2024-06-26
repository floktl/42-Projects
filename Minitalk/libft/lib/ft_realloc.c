/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:50:22 by flo               #+#    #+#             */
/*   Updated: 2024/03/30 12:49:54 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

//	function to allocate memory to an existing datatype
void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = NULL;
	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
		return (NULL);
	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	ptr = NULL;
	return (new_ptr);
}
