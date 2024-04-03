/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:00:27 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/03 15:21:54 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//	function to assign the arguments from the user input into the philo struct
int	assign_arguments(t_data *data, char **args, int arg_count)
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
	data->num_philo = ft_atoi(args[1]);
	data->time_to_die = ft_atoi(args[2]);
	data->time_to_eat = ft_atoi(args[3]);
	data->time_to_sleep = ft_atoi(args[4]);
	if (arg_count == 6)
		data->num_of_times_eat = ft_atoi(args[5]);
	else
		data->num_of_times_eat = INT_MAX;
	gettimeofday(&data->time, NULL);
	printf("arguments correct, proceeding with initializing philosophers...\n");
	return (EXIT_SUCCESS);
}

//	assign and mallocate all necessary memory for each philosopher
int	assign_individual_philosopher_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		data->philos[i].id = i + 1;
		if (data->philos[i].id != data->num_philo)
		{
			data->philos[i].right_fork = malloc(sizeof(pthread_mutex_t));
			if (pthread_mutex_init(data->philos[i].right_fork, NULL) != 0)
				return (ft_p_error("pthread_mutex_init failed!\n"));
		}
		if (i == 0)
		{
			data->philos[i].left_fork = malloc(sizeof(pthread_mutex_t));
			if (data->philos[i].left_fork == NULL)
				return (ft_p_error("Memory allocation failed!\n"));
			if (pthread_mutex_init(data->philos[i].left_fork, NULL) != 0)
				return (ft_p_error("pthread_mutex_init failed!\n"));
			data->philos[data->num_philo - 1].right_fork = data->philos[i].left_fork;
		}
		else
			data->philos[i].left_fork = data->philos[i - 1].left_fork;
		data->philos[i].thread = malloc(sizeof(pthread_t));
		if (data->philos[i].thread == NULL)
			return (ft_p_error("Memory allocation failed!\n"));
		data->philos[i].data = data;
		i++;
	}
	return (EXIT_SUCCESS);
}

//	initialize the struct with all needed values for this project
int	initialize_philosophers(t_data *data, char **args, int arg_count)
{
	if (assign_arguments(data, args, arg_count) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->num_philo);
	if (data->philos == NULL)
		return (ft_p_error("Philo memory allocation failed\n"));
	if (assign_individual_philosopher_data(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
