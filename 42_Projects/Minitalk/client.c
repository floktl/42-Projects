/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:32:57 by fkeitel           #+#    #+#             */
/*   Updated: 2024/01/10 18:33:58 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//
//client
//

void	handle_sigusr(int signum)
{
	if (signum == SIGUSR1)
		printf("message received");
}

void	send_bits(char cur_char, pid_t server_pid)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (cur_char & (1 << j))
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				perror("Error sending signal");
				exit(1);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				perror("Error sending signal");
				exit(1);
			}
		}
		usleep(90);
		j++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*message;
	int		i;
	char	message_start;

	message_start = 'a';
	server_pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		ft_printf("Usage: %s <Server PID> <Message>\n", argv[0]);
		return (1);
	}
	i = 0;
	message = ft_itoa(ft_strlen(argv[2]));
	message = ft_strjoin(message, &message_start);
	while (message[i])
	{
		send_bits(message[i], server_pid);
		i++;
	}
	i = 0;
	message = argv[2];
	signal(SIGUSR1, handle_sigusr);
	while (message[i])
	{
		send_bits(message[i], server_pid);
		i++;
	}
	i = 0;
	message = ft_itoa((int)getpid());
	while (message[i])
	{
		send_bits(message[i], server_pid);
		i++;
	}
	return (0);
}
