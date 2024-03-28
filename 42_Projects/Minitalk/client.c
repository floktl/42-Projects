/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:32:57 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/27 17:31:40 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//
//client, sends a message given as argument to the server
//

//function to print a message, if a message from the server is received
void	handle_sigusr(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("message received\n");
}

//function to send a character in single bits per send
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
				ft_printf("Error sending signal");
				exit(1);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				ft_printf("Error sending signal");
				exit(1);
			}
		}
		usleep(100);
		j++;
	}
}

//function to return the message filled with arguments and placeholder 'a'
char	*prepare_message(char *args)
{
	char	*message;
	char	*temp;
	char	args_len_end;

	message = ft_itoa((int)ft_strlen(args));
	args_len_end = MESSAGE_END;
	temp = ft_strjoin(message, &args_len_end);
	free(message);
	message = ft_strjoin(temp, args);
	free(temp);
	return (message);
}

//main function, message structure, which will be send to the server:
// <length of arg[]> 'a' <argument> <client_pid>
//client_pid is for return signal from server, checks if message received
int	main(int argc, char *argv[])
{
	pid_t		server_pid;
	char		*message;
	int			counter;
	char		*pid_in_char;
	char		*temp_message;

	counter = 0;
	signal(SIGUSR1, handle_sigusr);
	if (argc != 3 || ft_strlen(argv[2]) == 0)
		return (ft_printf("Usage: %s <Server PID> <Message>\n", argv[0]), 1);
	server_pid = ft_atoi(argv[1]);
	temp_message = prepare_message(argv[2]);
	pid_in_char = ft_itoa((int)getpid());
	message = ft_strjoin(temp_message, pid_in_char);
	free(temp_message);
	free(pid_in_char);
	while (message[counter])
		send_bits(message[counter++], server_pid);
	free(message);
	send_bits(MESSAGE_END, server_pid);
	return (0);
}
