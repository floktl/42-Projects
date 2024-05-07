/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:13:42 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/07 14:17:08 by fkeitel          ###   ########.fr       */
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

//	function to check if one philo is dead
void	*death_checker(void *arg)
{
	struct timeval	start;
	t_data			*data;
	int				i;
	long			time;
	int				philo_num;

	data = (t_data *)arg;
	i = 0;
	usleep(1000);
	while (1)
	{
		i = 0;
		while (i < data->num_philo)
		{
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
					philo_num = i;
					update_timestamp(&data->philos[philo_num]);
					i = 0;
					while (i < data->num_philo)
					{
						pthread_mutex_lock(&data->philos[i].death_mutex);
						data->philos[i].dead = DEAD;
						pthread_mutex_unlock(&data->philos[i].death_mutex);
						i++;
					}
					printf("\033[1;31m%ld\033[0m\n", time);
					printf("\033[1;31m%ld %d died\033[0m\n", data->philos[philo_num].time, data->philos[philo_num].id);
					return (DEAD);
				}
			}
			else
				pthread_mutex_unlock(&data->philos[i].eat_mutex);
			i++;
		}
		usleep(250);
	}
}
