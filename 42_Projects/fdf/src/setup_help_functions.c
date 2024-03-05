/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_help_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:36:30 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/02 09:40:36 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//	find and sets a pointer to the last coordinate in y direction (before_y)
void	ft_set_before_y(t_coord **head, int iterations, t_window *window)
{
	t_coord	*current;
	int		counter;
	int		count_temp;
	t_coord	*temp;

	current = *head;
	counter = 0;
	count_temp = iterations - window->map_sz.xm_size;
	temp = NULL;
	while (current != NULL && iterations > 0)
	{
		if (count_temp == 0)
		{
			temp = current;
			count_temp = -1;
		}
		else if (count_temp > 0)
			count_temp--;
		if (counter == iterations)
		{
			if (temp != NULL)
				current->before_y = temp;
			break ;
		}
		current = current->next;
		counter++;
	}
}

//	find and sets a pointer to the next coordinate in y direction (next_y)
void	ft_set_after_y(t_coord *head, t_window *window)
{
	t_coord	*current;
	t_coord	*current2;
	int		counter;

	current = head;
	while (current != NULL)
	{
		counter = 0;
		current2 = current;
		while (current2 != NULL && counter <= window->map_sz.xm_size)
		{
			if (counter == window->map_sz.xm_size)
				current->next_y = current2;
			current2 = current2->next;
			counter++;
		}
		current = current->next;
	}
}

//	returns the necessary iterations of coordinate to the next y value (same x)
int	get_index(t_window *window, int pos_xm, int pos_ym)
{
	if (pos_xm < 1 || pos_ym < 1
		|| pos_xm > window->map_sz.xm_size || pos_ym > window->map_sz.ym_size)
	{
		return (-1);
	}
	return (window->map_sz.xm_size * (pos_ym) + (pos_xm - 1));
}

//printf("cy; %d | %d\t", current->pos_xm, current->pos_ym);
//if (current->before != NULL)
//	printf("bx; %d | %d\t", current->before->pos_xm, current->before->pos_ym);
//else
//	printf("bx; 0 | 0\t");
//if (current->before_y != NULL)
//	printf("by; %d | %d\t", current->before_y->pos_xm,
	//current->before_y->pos_ym);
//else
//	printf("by; 0 | 0\t");
//if (current->next_y != NULL)
//	printf("bn; %d | %d\t\n", current->next_y->pos_xm, current->next_y->pos_ym);
//else
//	printf("bn; 0 | 0\t\n");