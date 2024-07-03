/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:58:02 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 17:40:16 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * function to count the nodes of a linked list
 *
 * @param lst the linked list poited at the start
 * @return the number of nodes
 */
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
