/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:50:22 by flo               #+#    #+#             */
/*   Updated: 2024/04/23 11:45:10 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//	function to allocate memory to an existing datatype
void *ft_realloc(void *ptr, size_t size) {
    void **new_ptr = NULL;

    // If ptr is NULL, simply allocate new memory
    if (ptr == NULL) {
        return malloc(size);
    }

    // If size is 0, free the existing memory and return NULL
    if (size == 0) {
        free(ptr);
        return NULL;
    }

    // Allocate memory for the new array of pointers
    new_ptr = malloc(size);
    if (!new_ptr) {
        return NULL; // Memory allocation failed
    }

    // Copy the contents of the old array to the new array
    ft_memcpy(new_ptr, ptr, sizeof(void *)); // Copy the array of pointers

    // Free the old array
    free(ptr);

    return new_ptr;
}

