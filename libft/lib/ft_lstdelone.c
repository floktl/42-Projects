/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:57:39 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 17:32:48 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * function to free a node of a linked list and its content
 *
 * @param lst the node
 * @param del the free function
 */
void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
