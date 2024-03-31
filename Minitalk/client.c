/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:32:57 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/30 11:32:47 by flo              ###   ########.fr       */
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
		ft_printf("\033[0;32mmessage received\033[0m\n");
}

//function to send a character in single bits per send
int	send_bits(char cur_char, pid_t server_pid)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (cur_char & (1 << j))
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				ft_printf("\033[0;31merror sending signal\033[0m\n");
				return (EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				ft_printf("\033[0;31merror sending signal\033[0m\n");
				return (EXIT_FAILURE);
			}
		}
		usleep(100);
		j++;
	}
	return (EXIT_SUCCESS);
}

//function to return the message filled with arguments and placeholder 'a'
char	*prepare_message(char *args)
{
	char	*message;
	char	*temp;
	char	args_len_end;

	temp = NULL;
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
int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;
	int		counter;
	char	*pid_in_char;
	char	*temp_message;

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
	{
		if (send_bits(message[counter], server_pid) == EXIT_FAILURE)
			return (free(message), 0);
		counter++;
	}
	free(message);
	send_bits(MESSAGE_END, server_pid);
	return (0);
}
