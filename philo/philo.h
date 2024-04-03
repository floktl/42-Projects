/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:07:06 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/03 15:17:02 by fkeitel          ###   ########.fr       */
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

//	predefinition of the global data struct
typedef struct s_data	t_data;

//	struct for the data of each philo
typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		*thread;
	struct s_data	*data;
}	t_philo;

//	struct for the global data
typedef struct s_data
{
	struct timeval	time;
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_eat;
	struct s_philo	*philos;
}		t_data;

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

int		assign_arguments(t_data *data, char **args, int arg_count);
int		initialize_philosophers(t_data *data, char **args, int arg_count);
void	free_data_struct(t_data *philo);

#endif