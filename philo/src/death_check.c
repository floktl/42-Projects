/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:13:42 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/09 14:36:16 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//	function to cheack for a death of a philosopher using a seperate mutex
int	check_death(t_philo *philo)
{
	int	dead_status;

	pthread_mutex_lock(&philo->death_mutex);
	dead_status = philo->dead;
	return (dead_status);
}

//	function to set all philos to the dead status
void	set_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_lock(&data->philos[i].death_mutex);
		data->philos[i].dead = DEAD;
		pthread_mutex_unlock(&data->philos[i].death_mutex);
		i++;
	}
}

//	funciton to check if one philo is hungry
int	check_hungry_status(t_data *data, int i)
{
	long			time;
	struct timeval	start;

	pthread_mutex_lock(&data->philos[i].eat_mutex);
	if (data->philos[i].is_hungry == HUNGRY)
	{
		pthread_mutex_unlock(&data->philos[i].eat_mutex);
		pthread_mutex_lock(&data->philos[i].meal_mutex);
		gettimeofday(&start, NULL);
		time = ((start.tv_sec) * 1000LL + (start.tv_usec) / 1000)
			- data->philos[i].last_meal;
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		if (time > data->die_time)
		{
			set_death(data);
			update_timestamp(&data->philos[i]);
			printf("\033[1;31m%ld %d died\033[0m\n",
				data->philos[i].time, data->philos[i].id);
			return (DEAD);
		}
	}
	else
		pthread_mutex_unlock(&data->philos[i].eat_mutex);
	return (ALIVE);
}

//	function to check if one philo is dead or has eaten enough
void	*death_checker(void *arg)
{
	t_data			*data;
	int				i;
	int				sum;

	data = (t_data *)arg;
	i = 0;
	usleep(1000);
	while (data->num_philo > 1)
	{
		i = 0;
		sum = 0;
		while (i < data->num_philo)
		{
			if (check_hungry_status(data, i) == DEAD)
				return (NULL);
			pthread_mutex_lock(&data->philos[i].round_mutex);
			sum += data->philos[i].num_of_times_eat;
			pthread_mutex_unlock(&data->philos[i].round_mutex);
			if (sum <= 0 && data->num_of_times_eat >= 0)
				return (set_death(data), NULL);
			i++;
		}
		usleep(250);
	}
	return (NULL);
}
