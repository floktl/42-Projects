/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:07:06 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/02 16:25:26 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
------------------------------- initial setup ----------------------------------
 */

//	header file
#ifndef PHILO_H
# define PHILO_H

/* ------------------------------- libraries -------------------------------- */

//	public libraries
# include <fcntl.h>
# include <stdint.h>
# include <limits.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/* -------------------------------- structs --------------------------------- */

// long
typedef struct s_philo
{
	struct timeval	time;
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_eat;
	pthread_mutex_t	*forks;
	pthread_t		*philos;
	int				*ids;
}	t_philo;

/*
--------------------------------- functions ------------------------------------
*/

//	dining problem functions:

void	*philosopher(void *arg);

//	helper functions:

int		ft_atoi(const char *str);
int		ft_p_error(char *error_string);
int		ft_isdigit(int c);

//	setup functions:

int		assign_arguments(t_philo *philo, char **args, int arg_count);
int		initialize_philosophers(t_philo *philo, char **args, int arg_count);
void	free_philo_struct(t_philo *philo);

#endif