/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:00:27 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/02 16:09:41 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//	function to assign the arguments from the user input into the philo struct
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
	{
		free(philo->philos);
		return (ft_p_error("Forks memory allocatation failed\n"));
	}
	philo->ids = (int *)malloc(sizeof(int) * philo->num_philo);
	if (philo->ids == NULL)
	{
		free(philo->philos);
		free(philo->forks);
		return (ft_p_error("ids memory allocatation failed\n"));
	}
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
