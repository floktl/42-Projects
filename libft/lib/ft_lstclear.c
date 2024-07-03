/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:57:35 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 17:32:05 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * function to free a linked list and its content
 *
 * @param lst the linked list
 * @param del the free function
 */
void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*current;
	t_list	*next;

	if (*lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		del(current-> content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
