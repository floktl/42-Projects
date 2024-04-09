/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:00:49 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/09 17:38:47 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//	main function user input (times in ms):
//	<num_philo> <time_to_die> <time_to_eat> <time_to_sleep> <num_of_times_eat>
int	main(int argc, char **argv)
{
	int		i;
	t_data	data;

	if (initialize_philosophers(&data, argv, argc) == EXIT_FAILURE)
		return (ft_p_error("\033[1;31mError initiliaz. Philosophers\033[0m\n"));
	i = 0;
	gettimeofday(&data.start_time, NULL);
	gettimeofday(&data.time, NULL);
	while (i < data.num_philo)
	{
		if (pthread_create(&data.philos[i].thread, NULL,
				philosopher, &data.philos[i]) != 0)
			return (ft_p_error("\033[1;31mpthread_create failed!\033[0m\n"));
		i++;
	}
	i = 0;
	while (i < data.num_philo)
	{
		if (pthread_join(data.philos[i].thread, NULL) != 0)
			return (ft_p_error("\033[1;31mpthread_join failed!\033[0m\n"));
		i++;
	}
	free_data_struct(&data);
	return (EXIT_SUCCESS);
}
