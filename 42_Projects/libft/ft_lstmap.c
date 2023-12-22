/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:57:53 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/20 16:21:31 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function creates a new linked list by applying function f to each-
// element of list, uses del to free elements if memory allocation fails.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*new_list;
	void	*temp;

	if (!f || !lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		temp = f(lst->content);
		current = ft_lstnew(temp);
		if (current == NULL)
		{
			free(temp);
			ft_lstclear(&new_list, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_list, current);
		lst = lst->next;
	}
	return (new_list);
}
