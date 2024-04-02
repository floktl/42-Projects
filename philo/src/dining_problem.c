/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_problem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:01:21 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/02 16:01:34 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//	actual code for the philosophers dining problem
void	*philosopher(void *arg)
{
	t_philo	*philo = NULL;
	int		id = *((int *)philo->ids);
	int		left_fork = id;
	int		right_fork = (id + 1) % philo->num_philo;

	philo = arg;
	while (1)
	{
		//eigene usleep()
		printf("%ld %d is thinking\n", philo->time.tv_usec / 1000, id);
		usleep(rand() % 1000);
		pthread_mutex_lock(&philo->forks[left_fork]);
		printf("%ld %d picked up left fork\n", philo->time.tv_usec / 1000, id);
		pthread_mutex_lock(&philo->forks[right_fork]);
		printf("%ld %d picked up right fork\n", philo->time.tv_usec / 1000, id);
		printf("%ld %d is eating\n", philo->time.tv_usec / 1000, id);
		usleep(rand() % 1000);
		pthread_mutex_unlock(&philo->forks[left_fork]);
		printf("%ld %d put down left fork\n", philo->time.tv_usec / 1000, id);
		pthread_mutex_unlock(&philo->forks[right_fork]);
		printf("%ld %d put down right fork\n", philo->time.tv_usec / 1000, id);
	}
}
