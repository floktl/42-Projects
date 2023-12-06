/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:57:53 by fkeitel           #+#    #+#             */
/*   Updated: 2023/10/18 16:41:11 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*new_list;

	if (!f || !lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		current = ft_lstnew(f(lst->content));
		if (current == NULL)
		{
			ft_lstclear(&new_list, (*del));
			free(current->content);
			return (NULL);
		}
		ft_lstadd_back(&new_list, current);
		lst = lst->next;
	}
	return (new_list);
}
