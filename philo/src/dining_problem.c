/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_problem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:01:21 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/06 13:28:37 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_and_sleep(t_philo *philo, long timestamp_in_ms)
{
	printf("%ld %d is thinking\n", timestamp_in_ms, philo->id);
	usleep(rand() % 1000);
	pthread_mutex_lock(philo->left_fork);
	printf("%ld %d picked up left fork\n", timestamp_in_ms, philo->id);
	pthread_mutex_lock(philo->right_fork);
	printf("%ld %d picked up right fork\n", timestamp_in_ms, philo->id);
	printf("%ld %d is eating\n", timestamp_in_ms, philo->id);
	philo->num_of_times_eat++;
	usleep(philo->data->time_to_eat % 1000);
	gettimeofday(&philo->last_meal_time, NULL);
	pthread_mutex_unlock(philo->left_fork);
	printf("%ld %d put down left fork\n", timestamp_in_ms, philo->id);
	pthread_mutex_unlock(philo->right_fork);
	printf("%ld %d put down right fork\n", timestamp_in_ms, philo->id);
	printf("%ld %d is sleeping\n", timestamp_in_ms, philo->id);
	usleep(philo->data->time_to_sleep % 1000);
}

//	actual code for the philosophers dining problem
void	*philosopher(void *arg)
{
	t_philo			*philo;
	struct timeval	time;
	struct timeval	start_time;
	long			timestamp;
	long			time_until_last_meal;

	philo = (t_philo *)arg;
	gettimeofday(&start_time, NULL);
	gettimeofday(&philo->last_meal_time, NULL);
	while (1)
	{
		pthread_mutex_lock(&philo->data->death_mutex);
		if (philo->data->philo_dead == TRUE)
		{
			pthread_mutex_unlock(&philo->data->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->death_mutex);
		gettimeofday(&time, NULL);
		time_until_last_meal = (time.tv_sec - philo->last_meal_time.tv_sec)
			* 1000000 + (time.tv_usec - philo->last_meal_time.tv_usec);
		if (time_until_last_meal > philo->data->time_to_die)
		{
			printf("\033[1;31m%ld %d died\033[0m\n", timestamp, philo->id);
			pthread_mutex_lock(&philo->data->death_mutex);
			philo->data->philo_dead = TRUE;
			pthread_mutex_unlock(&philo->data->death_mutex);
			break ;
		}
		timestamp = (time.tv_sec - start_time.tv_sec) * 1000LL
			+ (time.tv_usec - start_time.tv_usec) / 1000;
		print_and_sleep(philo, timestamp);
	}
	return (NULL);
}
