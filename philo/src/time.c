/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:12:39 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/09 16:52:36 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//	function to update the timestamp using a seperate mutex
void	update_timestamp(t_data *data, long *timestamp, t_philo *philo)
{
	pthread_mutex_lock(&data->time_mutex);
	gettimeofday(&data->time, NULL);
	pthread_mutex_unlock(&data->time_mutex);
	*timestamp = (data->time.tv_sec - data->start_time.tv_sec) * 1000LL
		+ (data->time.tv_usec - data->start_time.tv_usec) / 1000;
	philo->last_meal = (philo->data->time.tv_sec - philo->last_meal_time.tv_sec)
		* 1000LL + (philo->data->time.tv_usec
			- philo->last_meal_time.tv_usec) / 1000;
}

//	usleep function to check if the death time is reached
int	ft_usleep(t_philo *philo, long max_time, long *timestamp)
{
	long	i;
	long	death_time;

	i = 0;
	update_timestamp(philo->data, timestamp, philo);
	death_time = philo->last_meal;
	while (i < max_time)
	{
		usleep(1000);
		pthread_mutex_lock(&philo->data->death_mutex);
		if (death_time > philo->data->time_to_die)
		{
			if (philo->data->philo_dead == DEAD)
				return (DEAD);
			update_timestamp(philo->data, timestamp, philo);
			philo->data->philo_dead = DEAD;
			printf("last meal!: %ld\n", philo->last_meal);
			printf("\033[1;31m%ld %d died\033[0m\n", *timestamp, philo->id);
			return (DEAD);
		}
		pthread_mutex_unlock(&philo->data->death_mutex);
		i++;
		death_time++;
	}
	return (ALIVE);
}
