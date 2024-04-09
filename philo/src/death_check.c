/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:13:42 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/09 15:18:24 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//	function to cheack for a death of a philosopher using a seperate mutex
int	check_death(t_data *data)
{
	int	dead_status;

	pthread_mutex_lock(&data->death_mutex);
	dead_status = data->philo_dead;
	return (dead_status);
}

//	check if the time to die is due for each philosopher
int	check_death_time(t_philo *philo, long *timestamp)
{
	if (check_death(philo->data) == DEAD)
		return (pthread_mutex_unlock(&philo->data->death_mutex), DEAD);
	update_timestamp(philo->data, timestamp, philo);
	if (philo->last_meal > philo->data->time_to_die
		|| philo->data->philo_dead == DEAD)
	{
		if (philo->data->philo_dead == DEAD)
			return (DEAD);
		philo->data->philo_dead = DEAD;
		printf("last meal: %ld\n", philo->last_meal);
		printf("\033[1;31m%ld %d died\033[0m\n", *timestamp, philo->id);
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (DEAD);
	}
	return (ALIVE);
}

//	function to check, if a philosopher has eaten as many times as argument
int	check_num_of_timeseat(t_philo *philo)
{
	philo->num_of_times_eat--;
	if (philo->num_of_times_eat == 0)
	{
		pthread_mutex_lock(&philo->data->death_mutex);
		philo->data->philo_dead = DEAD;
		pthread_mutex_unlock(&philo->data->death_mutex);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		printf("\033[1;31mPhilo %d reached eat limit!\033[0m\n", philo->id);
		return (DEAD);
	}
	return (ALIVE);
}
