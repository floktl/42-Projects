/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:57:43 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 17:34:13 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * function to execute a function f on the content of all node of a linked list
 *
 * @param lst the linked list pointed at the start
 * @param del the function
 */
void	ft_lstiter(t_list *lst, void (*f)(int))
{
	t_list	*current;
	t_list	*next;

	if (lst == NULL)
		return ;
	current = lst;
	while (current != NULL)
	{
		next = current->next;
		f(current-> content);
		current = next;
	}
}
