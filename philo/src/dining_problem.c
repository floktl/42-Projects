/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_problem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:01:21 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/03 10:52:20 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	update_round_time(t_philo *philo, long *round_time)
{
	gettimeofday(&philo->time, NULL);
	*round_time = (philo->time.tv_sec - philo->data->start_time.tv_sec) * 1000LL
		+ (philo->time.tv_usec - philo->data->start_time.tv_usec) / 1000;
}
//	infinite loop for to keep each philosopher alive as long as possible
void	*philosopher(void *arg)
{
	t_philo			*philo;
	long			timestamp = 0;
	static long			round_time = 0;

	philo = (t_philo *)arg;
	gettimeofday(&philo->last_meal_time, NULL);
	while (1)
	{
		if (philo->status)
		{
			printf("%ld %d is thinking\n", timestamp, philo->id);
			while (round_time < (philo->data->time_to_eat + philo->data->time_to_sleep))
			{
				if (check_death_time(philo, &timestamp) == DEAD)
					break ;
				pthread_mutex_unlock(&philo->data->death_mutex);
				update_round_time(philo, &round_time);
			}
			philo->status *= -1;
		}
		if (!philo->status)
		{
			if (prepare_eating(philo, &timestamp) == DEAD)
				break ;
			if (prepare_sleeping(philo, &timestamp) == DEAD)
				break ;
		}
	}
	round_time = 0;
	return (NULL);
}

//	function for the eating part, including taking both forks
int	prepare_eating(t_philo *philo, long *timestamp)
{
	pthread_mutex_lock(philo->left_fork);
	if (check_death_time(philo, timestamp) == DEAD)
		return (pthread_mutex_unlock(philo->left_fork), DEAD);
	else
		printf("%ld %d has taken a fork\n", *timestamp, philo->id);
	pthread_mutex_unlock(&philo->data->death_mutex);
	pthread_mutex_lock(philo->right_fork);
	if (check_death_time(philo, timestamp) == DEAD)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (DEAD);
	}
	else
	{
		printf("%ld %d has taken a fork\n", *timestamp, philo->id);
		printf("%ld %d is eating\n", *timestamp, philo->id);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	if (check_num_of_timeseat(philo) == DEAD)
		return (DEAD);
	if (ft_usleep(philo, philo->data->time_to_eat, timestamp) == DEAD)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (DEAD);
	}
	return (ALIVE);
}

//	function for the sleeping part, including putting down the forks
int	prepare_sleeping(t_philo *philo, long *timestamp)
{
	gettimeofday(&philo->last_meal_time, NULL);
	pthread_mutex_unlock(philo->left_fork);
	if (check_death_time(philo, timestamp) == DEAD)
		return (pthread_mutex_unlock(philo->right_fork), DEAD);
	pthread_mutex_unlock(&philo->data->death_mutex);
	pthread_mutex_unlock(philo->right_fork);
	if (check_death_time(philo, timestamp) == DEAD)
		return (DEAD);
	else
	{
		printf("%ld %d is sleeping\n", *timestamp, philo->id);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	if (ft_usleep(philo, philo->data->time_to_sleep, timestamp) == DEAD)
	{
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (DEAD);
	}
	return (ALIVE);
}
