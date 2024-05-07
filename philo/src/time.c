/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:12:39 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/06 13:28:52 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	update_round_time(t_philo *philo, struct timeval start)
{
	struct timeval	cur;

	gettimeofday(&cur, NULL);
	pthread_mutex_lock(&philo->round_mutex);
	philo->round = (cur.tv_sec - start.tv_sec) * 1000LL
		+ (cur.tv_usec - start.tv_usec) / 1000;
	pthread_mutex_unlock(&philo->round_mutex);
}

//	function to update the timestamp using a seperate mutex
void	update_timestamp(t_philo *philo)
{
	struct timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	philo->time = ((cur_time.tv_sec) * 1000LL + (cur_time.tv_usec) / 1000)
		- philo->data->start_time;
}

//	usleep function to check if the death time is reached
int	ft_usleep(t_philo *philo, long max_time)
{
	struct timeval	start;
	struct timeval	cur;
	long			sleep_dur;
	long			start_time;

	gettimeofday(&start, NULL);
	start_time = (start.tv_sec) * 1000LL + (start.tv_usec) / 1000;
	while (1)
	{
		if (check_death(philo) == DEAD)
			return (DEAD);
		pthread_mutex_unlock(&philo->death_mutex);
		gettimeofday(&cur, NULL);
		sleep_dur = (cur.tv_sec * 1000LL + (cur.tv_usec) / 1000) - start_time;
		if (sleep_dur < max_time)
			usleep(250);
		else
			break ;
	}
	return (ALIVE);
}

void	update_last_meal_time(t_philo *philo)
{
	struct timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = (cur_time.tv_sec)
		* 1000LL + (cur_time.tv_usec) / 1000;
	pthread_mutex_unlock(&philo->meal_mutex);
}
