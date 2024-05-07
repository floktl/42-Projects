/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_problem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:01:21 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/07 15:45:32 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//	infinite loop for to keep each philosopher alive as long as possible
void	*philosopher(void *arg)
{
	t_philo			*philo;
	struct timeval	start_round;

	philo = (t_philo *)arg;
	update_last_meal_time(philo);
	while (1)
	{
		gettimeofday(&start_round, NULL);
		if (philo->status == -1)
		{
			philo->status *= -1;
			if (eating(philo, start_round) == DEAD)
				break ;
		}
		else if (philo->status == 1)
		{
			philo->status *= -1;
			if (sleeping(philo, start_round) == DEAD
				|| thinking(philo, start_round) == DEAD)
				break ;
		}
	}
	return (NULL);
}

//	function for the eating part, including taking both forks
int	eating(t_philo *philo, struct timeval start_round)
{
	(void)start_round;
	if (check_death(philo) == DEAD)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(&philo->death_mutex);
		return (DEAD);
	}
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->is_hungry = EATING;
	pthread_mutex_unlock(&philo->eat_mutex);
	update_timestamp(philo);
	printf("%ld %d has taken a fork\n", philo->time, philo->id);
	printf("%ld %d has taken a fork\n", philo->time, philo->id);
	printf("%ld %d is eating\n", philo->time, philo->id);
	pthread_mutex_unlock(&philo->death_mutex);
	if (ft_usleep(philo, philo->data->eat_time) == DEAD)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(&philo->death_mutex);
		return (DEAD);
	}
	update_last_meal_time(philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (ALIVE);
}

//	function for the sleeping part, including putting down the forks
int	sleeping(t_philo *philo, struct timeval start_round)
{
	int	hungry_status;

	pthread_mutex_lock(&philo->eat_mutex);
	hungry_status = philo->is_hungry;
	philo->is_hungry = HUNGRY;
	pthread_mutex_unlock(&philo->eat_mutex);
	if (hungry_status == HUNGRY)
		return (ALIVE);
	(void)start_round;
	if (check_death(philo) == DEAD)
		return (pthread_mutex_unlock(&philo->death_mutex), DEAD);
	update_timestamp(philo);
	printf("%ld %d is sleeping\n", philo->time, philo->id);
	pthread_mutex_unlock(&philo->death_mutex);
	if (ft_usleep(philo, philo->data->sleep_time) == DEAD)
	{
		return (pthread_mutex_unlock(&philo->death_mutex), DEAD);
	}
	return (ALIVE);
}

int	thinking(t_philo *philo, struct timeval start_round)
{
	(void)start_round;
	if (check_death(philo) == DEAD)
		return (pthread_mutex_unlock(&philo->death_mutex), DEAD);
	update_timestamp(philo);
	printf("%ld %d is thinking\n", philo->time, philo->id);
	pthread_mutex_unlock(&philo->death_mutex);
	usleep(100);
	return (ALIVE);
}
