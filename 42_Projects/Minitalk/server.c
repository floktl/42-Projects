/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:29:17 by fkeitel           #+#    #+#             */
/*   Updated: 2024/02/14 17:24:47 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//function to append a digit on an integer
int	append_int(int a, int b)
{
	int	multiplier;
	int	digits;
	int	i;
	int	n;

	n = b;
	i = 0;
	multiplier = 1;
	digits = 0;
	while (n != 0)
	{
		digits++;
		n /= 10;
	}
	while (i++ < digits)
		multiplier *= 10;
	return (a * multiplier + b);
}

//function to convert an array with 8 bits to a character
char	bits_to_char(const int bits[8])
{
	char	result;
	int		i;

	result = 0;
	i = 0;
	while (i < 8)
	{
		result |= bits[i] << i;
		i++;
	}
	return (result);
}

//function to output the current character or send the PID of the current
//process to the client, to check if message is received
void	output_message(char character, int *state, int *message_rest_length)
{
	static int	char_count = 0;
	static char	client_pid[6];

	if (*message_rest_length > 0)
	{
		*message_rest_length -= 1;
		write(STDOUT_FILENO, &character, 1);
	}
	else
	{
		if (character != 'a')
			client_pid[char_count++] = character;
		else if (character == 'a')
		{
			*state = 0;
			client_pid[char_count] = '\0';
			char_count = 0;
			if (kill((pid_t)ft_atoi(client_pid), SIGUSR1) == -1)
			{
				ft_printf("Error sending signal");
				exit(1);
			}
		}
	}
}

//function to handle the SIGUSR signals from the client
void	handle_sigusr(int signum)
{
	static int	current_char[8];
	static int	bit_counter = 0;
	char		character;
	static int	rest_len = 0;
	static int	state = 0;

	if (signum == SIGUSR1)
		current_char[bit_counter++] = 1;
	else if (signum == SIGUSR2)
		current_char[bit_counter++] = 0;
	if (bit_counter == 8)
	{
		bit_counter = 0;
		character = bits_to_char(current_char);
		if (character != 'a' && state == 0)
			rest_len = append_int(rest_len, ft_atoi(&character));
		else if (character == 'a' && state == 0)
			state = 1;
		else
			output_message(character, &state, &rest_len);
	}
}

int	main(void)
{
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
