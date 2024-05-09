/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_problem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:01:21 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/09 15:25:10 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//	infinite loop for to keep each philosopher alive as long as possible
void	*philosopher(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	update_last_meal_time(philo);
	while (philo->data->num_of_times_eat != 0)
	{
		if (philo->status == -1)
		{
			philo->status *= -1;
			if (eating(philo) == DEAD)
				break ;
		}
		else if (philo->status == 1)
		{
			philo->status *= -1;
			if (sleeping(philo) == DEAD || thinking(philo) == DEAD)
				break ;
		}
	}
	return (NULL);
}

//	function to take the forks and check if one philo died
int	take_forks(t_philo *philo)
{
	if (check_death(philo) == DEAD)
		return (pthread_mutex_unlock(&philo->death_mutex), DEAD);
	if (philo->id == philo->data->num_philo)
	{
		pthread_mutex_lock(&*(philo->left_fork));
		if (philo->data->num_philo > 1)
			pthread_mutex_lock(&*(philo->right_fork));
		else
		{
			printf("%ld %d has taken a fork\n", philo->time, philo->id);
			return (pthread_mutex_unlock(&*(philo->left_fork)), DEAD);
		}
	}
	else
	{
		pthread_mutex_lock(&*(philo->right_fork));
		pthread_mutex_lock(&*(philo->left_fork));
	}
	pthread_mutex_lock(&philo->eat_mutex);
	philo->is_hungry = EATING;
	pthread_mutex_unlock(&philo->eat_mutex);
	update_timestamp(philo);
	return (ALIVE);
}

//	function for the eating part, including taking both forks
int	eating(t_philo *philo)
{
	if (take_forks(philo) == DEAD)
		return (DEAD);
	printf("%ld %d has taken a fork\n", philo->time, philo->id);
	printf("%ld %d has taken a fork\n", philo->time, philo->id);
	printf("%ld %d is eating\n", philo->time, philo->id);
	update_last_meal_time(philo);
	pthread_mutex_unlock(&philo->death_mutex);
	if (ft_usleep(philo, philo->data->eat_time) == DEAD)
	{
		pthread_mutex_unlock(&*(philo->left_fork));
		pthread_mutex_unlock(&*(philo->right_fork));
		return (pthread_mutex_unlock(&philo->death_mutex), DEAD);
	}
	pthread_mutex_unlock(&*(philo->left_fork));
	pthread_mutex_unlock(&*(philo->right_fork));
	pthread_mutex_lock(&philo->round_mutex);
	philo->num_of_times_eat--;
	if (philo->num_of_times_eat == 0)
		return (pthread_mutex_unlock(&philo->round_mutex), DEAD);
	pthread_mutex_unlock(&philo->round_mutex);
	return (ALIVE);
}

//	function for the sleeping part, including putting down the forks
int	sleeping(t_philo *philo)
{
	int	hungry_status;

	pthread_mutex_lock(&philo->eat_mutex);
	hungry_status = philo->is_hungry;
	philo->is_hungry = HUNGRY;
	pthread_mutex_unlock(&philo->eat_mutex);
	if (hungry_status == HUNGRY)
		return (ALIVE);
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

//	function for the thinking part
int	thinking(t_philo *philo)
{
	if (check_death(philo) == DEAD)
		return (pthread_mutex_unlock(&philo->death_mutex), DEAD);
	update_timestamp(philo);
	printf("%ld %d is thinking\n", philo->time, philo->id);
	pthread_mutex_unlock(&philo->death_mutex);
	usleep(100);
	return (ALIVE);
}
