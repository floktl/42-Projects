/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_problem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:01:21 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/07 13:50:10 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//	function to update the timestamp using a seperate mutex
void	update_timestamp(t_data *data, long *timestamp)
{
	pthread_mutex_lock(&data->time_mutex);
	gettimeofday(&data->time, NULL);
	*timestamp = (data->time.tv_sec - data->start_time.tv_sec) * 1000LL
		+ (data->time.tv_usec - data->start_time.tv_usec) / 1000;
	pthread_mutex_unlock(&data->time_mutex);
}

//	function to cheack for a death of a philosopher using a seperate mutex
int	check_death(t_data *data)
{
	pthread_mutex_lock(&data->death_mutex);
	if (data->philo_dead == TRUE)
	{
		pthread_mutex_unlock(&data->death_mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(&data->death_mutex);
	return (FALSE);
}

//	check if the time to die is due for each philosopher
int	check_death_time(t_philo *philo, long *timestamp)
{
	update_timestamp(philo->data, timestamp);
	philo->last_meal = (philo->data->time.tv_sec - philo->last_meal_time.tv_sec)
		* 1000LL + (philo->data->time.tv_usec
			- philo->last_meal_time.tv_usec) / 1000;
	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->last_meal > philo->data->time_to_die)
	{
		printf("last meal: %ld\n", philo->last_meal);
		printf("\033[1;31m%ld %d died\033[0m\n", *timestamp, philo->id);
		philo->data->philo_dead = TRUE;
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (FALSE);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (TRUE);
}

//	usleep function to check if the death time is reached
int	ft_usleep(t_philo *philo, long max_time, long *timestamp)
{
	long	i;

	i = 0;
	while (i < max_time)
	{
		usleep(1000);
		if (check_death_time(philo, timestamp) == FALSE)
			return (FALSE);
		i++;
	}
	return (EXIT_SUCCESS);
}

//	function to manage the timing of each philosopher
int	print_and_sleep(t_philo *philo, long *timestamp)
{
	if (check_death_time(philo, timestamp) == FALSE)
		return (FALSE);
	printf("%ld %d is thinking\n", *timestamp, philo->id);
	pthread_mutex_lock(philo->left_fork);
	if (check_death_time(philo, timestamp) == FALSE)
		return (FALSE);
	printf("%ld %d picked up left fork\n", *timestamp, philo->id);
	pthread_mutex_lock(philo->right_fork);
	if (check_death_time(philo, timestamp) == FALSE)
		return (FALSE);
	printf("%ld %d picked up right fork\n", *timestamp, philo->id);
	printf("%ld %d is eating\n", *timestamp, philo->id);
	philo->num_of_times_eat--;
	//if (ft_usleep(philo, philo->data->time_to_eat * 1000, timestamp) == EXIT_FAILURE)
	//	return (pthread_mutex_unlock(philo->left_fork),
	//		pthread_mutex_unlock(philo->right_fork), FALSE);
	usleep(philo->data->time_to_eat * 1000);
	gettimeofday(&philo->last_meal_time, NULL);
	pthread_mutex_unlock(philo->left_fork);
	if (check_death_time(philo, timestamp) == FALSE)
		return (FALSE);
	printf("%ld %d put down left fork\n", *timestamp, philo->id);
	pthread_mutex_unlock(philo->right_fork);
	if (check_death_time(philo, timestamp) == FALSE)
		return (FALSE);
	printf("%ld %d put down right fork\n", *timestamp, philo->id);
	printf("%ld %d is sleeping\n", *timestamp, philo->id);
	usleep(philo->data->time_to_sleep * 1000);
	return (TRUE);
}

//	actual code for the philosophers dining problem
void	*philosopher(void *arg)
{
	t_philo			*philo;
	long			timestamp;

	philo = (t_philo *)arg;
	gettimeofday(&philo->last_meal_time, NULL);
	while (1)
	{
		if (check_death(philo->data) == TRUE)
			break ;
		if (print_and_sleep(philo, &timestamp) == FALSE)
			break ;
	}
	return (NULL);
}
