/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:23:22 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/09 14:12:18 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//	function to assign the fork adresses to each philo (left and right fork)
int	assign_fork_adresses(t_philo *philo, int i)
{
	pthread_mutex_t	*left_nb;
	pthread_mutex_t	*right_nb;

	if (i == 0)
	{
		left_nb = philo->data->philos[philo->data->num_philo - 1].right_fork;
		right_nb = philo->data->philos[i + 1].left_fork;
	}
	else if (i == philo->data->num_philo - 1)
	{
		left_nb = philo->data->philos[i - 1].right_fork;
		right_nb = philo->data->philos[0].left_fork;
	}
	else
	{
		left_nb = philo->data->philos[i - 1].right_fork;
		right_nb = philo->data->philos[i + 1].left_fork;
	}
	if (philo->left_fork != left_nb || philo->right_fork != right_nb)
		return (ft_p_error("Error in sorting!\n"));
	return (EXIT_SUCCESS);
}

//	safety function to check if forks are linked correctly with each neighbour
int	check_forks_consistency(t_data *data)
{
	t_philo			*philo;
	int				i;

	i = 0;
	if (!data || !data->philos || data->num_philo == 1)
		return (EXIT_FAILURE);
	while (i < data->num_philo)
	{
		philo = &data->philos[i];
		if (!philo->left_fork || !philo->right_fork || !philo->data)
			return (EXIT_FAILURE);
		if (assign_fork_adresses(philo, i) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

//	function to check if the arguemtns are within the limits
int	check_argument_limits(t_data *data, char **args, int arg_count)
{
	data->num_philo = ft_atoi(args[1]);
	data->die_time = ft_atoi(args[2]);
	data->eat_time = ft_atoi(args[3]);
	data->sleep_time = ft_atoi(args[4]);
	if (arg_count == 6)
	{
		data->num_of_times_eat = ft_atoi(args[5]);
		if (data->num_of_times_eat < 0)
			return (EXIT_FAILURE);
	}
	else
		data->num_of_times_eat = -1;
	if (data->die_time < 60
		|| data->num_philo > 200 || data->num_philo < 0
		|| data->die_time > 30000 || data->die_time < 120
		|| data->eat_time > 30000 || data->eat_time < 60
		|| data->sleep_time > 30000 || data->sleep_time < 60)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
