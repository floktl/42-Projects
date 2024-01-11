/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:29:17 by fkeitel           #+#    #+#             */
/*   Updated: 2024/01/10 18:14:44 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static char	client_pid[6];

int countDigits(int n) {
    int count = 0;
    do {
        count++;
        n /= 10;
    } while (n != 0);
    return count;
}

int appendInt(int a, int b) {
    int multiplier = 1;
    int digits = countDigits(b);

    for (int i = 0; i < digits; i++) {
        multiplier *= 10;
    }

    return a * multiplier + b;
}

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

void	handle_sigusr(int signum)
{
	static int	current_char[8];
	static int	bit_counter = 0;
	static int	char_count = 0;
	char		character;
	static int	message_length = 0;
	static int	state = 0;

	if (signum == SIGUSR1)
		current_char[bit_counter] = 1;
	if (signum == SIGUSR2)
		current_char[bit_counter] = 0;
	bit_counter++;
	if (bit_counter == 8)
	{
		character = bits_to_char(current_char);
		if (character != 'a' && state == 0)
			message_length = appendInt(message_length, ft_atoi(&character));
		else if (character == 'a' && state == 0)
			state = 1;
		else
			state = 2;
		if (message_length > 0 && state == 2)
		{
			message_length--;
			write(STDOUT_FILENO, &character, 1);
		}
		if (message_length == 0)
		{
			client_pid[char_count - 1] = character;
			if (char_count == 5 && state == 2)
			{
				state = 0;
				client_pid[5] = '\0';
				if (kill((pid_t)ft_atoi(client_pid), SIGUSR1) == -1)
				{
					perror("Error sending signal");
					exit(1);
				}
				char_count = 0;
			}
			else
				char_count++;
		}
		bit_counter = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
