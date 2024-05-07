/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:00:27 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/07 12:18:30 by fkeitel          ###   ########.fr       */
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
	if (check_argument_limits(data, args, arg_count) == EXIT_FAILURE)
		return (ft_p_error("Error in Argument\n"));
	printf("arguments correct, proceeding with initializing philosophers...\n");
	return (EXIT_SUCCESS);
}

//	helper function to allocate memory for the forks and link them
int	allocate_mutexes(t_data *data, int i, char which_fork)
{
	if (which_fork == 'l')
	{
		data->philos[i].left_fork = malloc(sizeof(pthread_mutex_t));
		if (data->philos[i].left_fork == NULL)
			return (ft_p_error("Memory allocation failed!\n"));
		if (pthread_mutex_init(data->philos[i].left_fork, NULL) != 0)
			return (ft_p_error("pthread_mutex_init failed!\n"));
		data->philos[data->num_philo -1].right_fork = data->philos[i].left_fork;
	}
	else if (which_fork == 'r')
	{
		data->philos[i].right_fork = malloc(sizeof(pthread_mutex_t));
		if (data->philos[i].right_fork == NULL)
			return (ft_p_error("Memory allocation failed!\n"));
		if (pthread_mutex_init(data->philos[i].right_fork, NULL) != 0)
			return (ft_p_error("pthread_mutex_init failed!\n"));
	}
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
		if (data->philos[i].id % 2 == 0)
			data->philos[i].status = 1;
		else
			data->philos[i].status = -1;
		if (i < data->num_philo - 1)
			if (allocate_mutexes(data, i, 'r') == EXIT_FAILURE)
				return (EXIT_FAILURE);
		if (i == 0)
		{
			if (allocate_mutexes(data, i, 'l') == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else
			data->philos[i].left_fork = data->philos[i - 1].right_fork;
		data->philos[i].num_of_times_eat = data->num_of_times_eat;
		data->philos[i].data = data;
		pthread_mutex_init(&data->philos[i].death_mutex, NULL);
		pthread_mutex_init(&data->philos[i].meal_mutex, NULL);
		pthread_mutex_init(&data->philos[i].round_mutex, NULL);
		pthread_mutex_init(&data->philos[i].eat_mutex, NULL);
		data->philos[i].last_meal = 0;
		data->philos[i].time = 0;
		data->philos[i].dead = ALIVE;
		data->philos[i].is_hungry = HUNGRY;
		i++;
	}
	return (EXIT_SUCCESS);
}

//	initialize the struct with all needed values for this project
int	initialize_philosophers(t_data *data, char **args, int arg_count)
{
	if (arg_count != 5 && arg_count != 6)
	{
		printf("\033[1;36musuage: ./philo num_philo time_to_die time_to_eat");
		return (ft_p_error(" time_to_sleep (num_of_times_eat)\033[0m\n"));
	}
	if (assign_arguments(data, args, arg_count) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	if (data->num_philo == 1)
		return (EXIT_FAILURE);
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->num_philo);
	if (data->philos == NULL)
		return (ft_p_error("Philo memory allocation failed\n"));
	if (assign_individual_philosopher_data(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_forks_consistency(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
