/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:00:49 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/03 15:20:38 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// This function checks if the character c is a decimal digit (0-9)
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

//function to print an error string and returning EXIT_FAILURE
int	ft_p_error(char *error_string)
{
	printf("%s", error_string);
	return (EXIT_FAILURE);
}

//	function to convert a string of characters into an integer
int	ft_atoi(const char *str)
{
	int	sign;
	int	count;
	int	result;

	sign = 1;
	count = 0;
	result = 0;
	while (str[count] == ' ' || (str[count] >= '\t' && str[count] <= '\r'))
		count++;
	if (str[count] == '-')
		sign = -1;
	if (str[count] == '-' || str[count] == '+')
		count++;
	while (str[count] >= '0' && str[count] <= '9')
	{
		while (ft_isdigit(str[count]))
		{
			result *= 10;
			result += str[count] - '0';
			count++;
		}
	}
	return (result * sign);
}

//	function to free the entire philo struct
void	free_data_struct(t_data *data)
{
	int	i;

	i = 0;
	if (!data)
		return ;
	while (i < data->num_philo)
	{
		if (data->philos[i].right_fork)
		{
			pthread_mutex_destroy(data->philos[i].right_fork);
			free(data->philos[i].right_fork);
			data->philos[i].right_fork = NULL;
		}
		if (data->philos[i].thread)
		{
			free(data->philos[i].thread);
			data->philos[i].thread = NULL;
		}
		i++;
	}
	if (data->philos)
	{
		free(data->philos);
		data->philos = NULL;
	}
}
