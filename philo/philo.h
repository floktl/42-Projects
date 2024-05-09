/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:07:06 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/09 13:36:24 by fkeitel          ###   ########.fr       */
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
# define EATING 1
# define HUNGRY 0
# define FULL 0
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
	pthread_mutex_t	eat_mutex;
	int				is_hungry;
	pthread_mutex_t	meal_mutex;
	long			last_meal;
	pthread_mutex_t	round_mutex;
	int				num_of_times_eat;
	long			time;
	long			round;
	int				dead;
	pthread_mutex_t	death_mutex;
}	t_philo;

//	struct for the global data
typedef struct s_data
{
	long			start_time;
	int				num_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				num_of_times_eat;
	pthread_t		death_thread;
	struct s_philo	*philos;
}		t_data;

/*
--------------------------------- functions ------------------------------------
*/

//	death check function:

int		check_death(t_philo *philo);
void	*death_checker(void *arg);

//	time function:

void	update_round_time(t_philo *philo, struct timeval start_round);
void	update_timestamp(t_philo *philo);
int		ft_usleep(t_philo *philo, long max_time);
void	update_last_meal_time(t_philo *philo);

//	dining problem functions:

void	*philosopher(void *arg);
int		thinking(t_philo *philo);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);

//	helper functions:

int		ft_atoi(const char *str);
int		ft_p_error(char *error_string);
int		ft_isdigit(int c);
void	free_data_struct(t_data *philo);
void	print_fork_addresses(t_data *data);

//	setup functions:

int		assign_arguments(t_data *data, char **args, int arg_count);
int		allocate_mutexes(t_data *data, int i, char which_fork);
int		assign_individual_philosopher_data(t_data *data);
int		initialize_philosophers(t_data *data, char **args, int arg_count);

//	error functions

int		assign_fork_adresses(t_philo *philo, int i);
int		check_forks_consistency(t_data *data);
int		check_argument_limits(t_data *data, char **args, int arg_count);

#endif