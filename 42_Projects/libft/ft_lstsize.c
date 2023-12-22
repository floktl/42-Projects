/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:58:02 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/20 16:22:49 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//This function counts and returns the number of elements in a linked list.
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != 0)
	{
		count++;
		lst = lst -> next;
	}
	return (count);
}
