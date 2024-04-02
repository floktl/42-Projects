/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:00:49 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/02 16:06:34 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//	main function user input (times in ms):
//	<num_philo> <time_to_die> <time_to_eat> <time_to_sleep> <num_of_times_eat>
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
