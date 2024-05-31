/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:00:49 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/27 11:06:13 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
		free_data_struct(data);
		return (ft_p_error("assigning arguments Error\n"));
	}
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->num_philo);
	if (data->philos == NULL)
		return (ft_p_error("Philo memory allocation failed\n"));
	if (assign_individual_philosopher_data(data) == EXIT_FAILURE)
		return (free_data_struct(data), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

//	main function user input (times in ms):
//	<num_philo> <time_to_die> <time_to_eat> <time_to_sleep> <num_of_times_eat>
int	main(int argc, char **argv)
{
	int				i;
	t_data			data ;
	struct timeval	start;

	if (initialize_philosophers(&data, argv, argc) == EXIT_FAILURE)
		return (ft_p_error("\033[1;31mError initiliaz. Philosophers\033[0m\n"));
	i = 0;
	gettimeofday(&start, NULL);
	data.start_time = (start.tv_sec) * 1000LL + (start.tv_usec) / 1000;
	while (i < data.num_philo)
	{
		if (pthread_create(&data.philos[i].thread, NULL,
				philosopher, &data.philos[i]) != 0)
			return (ft_p_error("\033[1;31mpthread_create failed!\033[0m\n"));
		i++;
	}
	if (pthread_create(&data.death_thread, NULL, death_checker, &data) != 0
		|| pthread_join(data.death_thread, NULL) != 0)
		return (ft_p_error("\033[1;31mdeath_thread init failed!\033[0m\n"));
	i = 0;
	while (i < data.num_philo)
		if (pthread_join(data.philos[i++].thread, NULL) != 0)
			return (ft_p_error("\033[1;31mpthread_join failed!\033[0m\n"));
	return (free_data_struct(&data), EXIT_SUCCESS);
}
