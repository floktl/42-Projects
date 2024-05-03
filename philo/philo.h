/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:07:06 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/03 09:14:43 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
------------------------------- initial setup ----------------------------------
 */

//	header file
#ifndef PHILO_H
# define PHILO_H

# define ALIVE 1
# define DEAD 0
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

//	predefinition of the global data struct
typedef struct s_data	t_data;

//	struct for the data of each philo
typedef struct s_philo
{
	int				id;
	int				status;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	struct s_data	*data;
	int				num_of_times_eat;
	struct timeval	last_meal_time;
	long			last_meal;
	struct timeval	time;
}	t_philo;

//	struct for the global data
typedef struct s_data
{
	struct timeval	time;
	struct timeval	start_time;
	pthread_mutex_t	time_mutex;
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_eat;
	bool			philo_dead;
	pthread_mutex_t	death_mutex;
	struct s_philo	*philos;
}		t_data;

/*
--------------------------------- functions ------------------------------------
*/

//	death check function:

int		check_death(t_data *data);
int		check_death_time(t_philo *philo, long *timestamp);
int		check_num_of_timeseat(t_philo *philo);

//	time function:

void	update_timestamp(t_data *data, long *timestamp, t_philo *philo);
int		ft_usleep(t_philo *philo, long max_time, long *timestamp);

//	dining problem functions:

void	*philosopher(void *arg);
int		prepare_eating(t_philo *philo, long *timestamp);
int		prepare_sleeping(t_philo *philo, long *timestamp);

//	helper functions:

int		ft_atoi(const char *str);
int		ft_p_error(char *error_string);
int		ft_isdigit(int c);
void	free_data_struct(t_data *philo);

//	setup functions:

int		assign_arguments(t_data *data, char **args, int arg_count);
int		allocate_fork(t_data *data, int i, char which_fork);
int		assign_individual_philosopher_data(t_data *data);
int		initialize_philosophers(t_data *data, char **args, int arg_count);

//	error functions

int		assign_fork_adresses(t_philo *philo, int i);
int		check_forks_consistency(t_data *data);
int		check_argument_limits(t_data *data, char **args, int arg_count);

#endif