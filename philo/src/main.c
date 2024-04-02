/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:00:49 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/02 21:59:59 by flo              ###   ########.fr       */
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
	printf("%d %d %d %d %d\n", philo.num_philo, philo.time_to_die,
		philo.time_to_eat, philo.time_to_sleep, philo.num_of_times_eat);
	i = 0;
	while (i < philo.num_philo)
	{
		if (pthread_mutex_init(&philo.forks[i], NULL) != 0)
			return (ft_p_error("pthread_mutex_init failed!\n"));
		if (pthread_create(&philo.philos[i], NULL, philosopher, &philo.ids[i]) != 0)
			return (ft_p_error("pthread_create failed!\n"));
		philo.ids[i] = i;
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
