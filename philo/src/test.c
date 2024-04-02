/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:00:49 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/02 15:51:18 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

int	assign_arguments(t_philo *philo, char **args, int arg_count)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (ft_isdigit(args[i][j]) == 0)
			{
				printf("Error : Argument %d is not a valid number!\n", i + 1);
				return (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	philo->num_philo = ft_atoi(args[1]);
	philo->time_to_die = ft_atoi(args[2]);
	philo->time_to_eat = ft_atoi(args[3]);
	philo->time_to_sleep = ft_atoi(args[4]);
	if (arg_count == 6)
		philo->num_of_times_eat = ft_atoi(args[5]);
	else
		philo->num_of_times_eat = INT_MAX;
	gettimeofday(&philo->time, NULL);
	printf("arguments correct, proceeding with initializing philosophers...\n");
	return (EXIT_SUCCESS);
}

int	ft_p_error(char *error_string)
{
	printf("%s", error_string);
	return (EXIT_FAILURE);
}
//	initialize the struct with all needed values for this project
int	initialize_philosophers(t_philo *philo, char **args, int arg_count)
{
	int	i;

	if (assign_arguments(philo, args, arg_count) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	philo->philos = (pthread_t *)malloc(sizeof(pthread_t) * philo->num_philo);
	if (philo->philos == NULL)
		return (ft_p_error("Philo memory allocatation failed\n"));
	philo->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo->num_philo);
	if (philo->forks == NULL)
		return (ft_p_error("Forks memory allocatation failed\n"));
	philo->ids = (int *)malloc(sizeof(int) * philo->num_philo);
	if (philo->ids == NULL)
		return (ft_p_error("ids memory allocatation failed\n"));
	i = 0;
	while (i < philo->num_philo)
	{
		if (pthread_mutex_init(&philo->forks[i], NULL) != 0)
			return (ft_p_error("pthread_mutex_init failed!\n"));
		philo->philos[i] = (pthread_t)malloc(sizeof(pthread_t));
		if (!philo->philos[i])
			return (ft_p_error("philos memory allocation failed!\n"));
		i++;
	}
	return (EXIT_SUCCESS);
}


int	main(int argc, char **argv)
{
	int		i;
	t_philo	philo;

	if ((argc != 5 && argc != 6)
		|| initialize_philosophers(&philo, argv, argc) == EXIT_FAILURE)
		return (ft_p_error("Error initializing Philosophers\n"));
	i = 0;
	printf("1: %d 2: %d 3: %d 4: %d 5: %d", philo.num_philo, philo.time_to_die, philo.time_to_eat, philo.time_to_sleep, philo.num_of_times_eat);
	while (i < philo.num_philo)
	{
		philo.ids[i] = i;
		if (pthread_create(&philo.philos[i], NULL, philosopher, &philo) == -1)
			return (ft_p_error("Error creating threads\n"));
		i++;
	}
	i = 0;
	while (i < philo.num_philo)
	{
		if (pthread_join(philo.philos[i], NULL) == -1)
			return (ft_p_error("Error joining Philosophers\n"));
		i++;
	}
	i = 0;
	while (i < philo.num_philo)
	{
		if (pthread_mutex_destroy(&philo.forks[i]) == -1)
			return (ft_p_error("Error destroying Philosophers\n"));
		i++;
	}
	return (EXIT_SUCCESS);
}
