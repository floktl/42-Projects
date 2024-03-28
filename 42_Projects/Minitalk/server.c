/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:29:17 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/27 17:34:16 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//	function to print the message using the write function for quicker response
int	print_message(char **message, char *client_pid)
{
	int	i;

	i = 0;
	if (kill((pid_t)ft_atoi(client_pid), SIGUSR1) == -1)
	{
		ft_printf("Error sending signal");
		if (*message)
		{
			free(*message);
			*message = NULL;
		}
		return (EXIT_FAILURE);
	}
	if (*message)
	{
		while ((*message)[i])
		{
			write(1, &(*message)[i], 1);
			i++;
		}
		free(*message);
		(*message) = NULL;
	}
	return (EXIT_SUCCESS);
}

//	function to add one character to the message, reallocate memory
int	add_char(char **message, char character, int *byte, int *rest_len)
{
	*message = ft_realloc(*message, *byte + 1);
	if (!(*message))
		return (EXIT_FAILURE);
	(*message)[*byte] = character;
	(*message)[++(*byte)] = '\0';
	*rest_len -= 1;
	return (EXIT_SUCCESS);
}

//	function to output the current character or send the PID of the current
//	process to the client, to check if message is received
void	output_message(char character, int *state, int *rest_len)
{
	static int	char_count = 0;
	static char	client_pid[6] = {0};
	static char	*message = NULL;
	static int	byte = 0;

	if (*rest_len > 0)
	{
		if (add_char(&message, character, &byte, rest_len) == EXIT_FAILURE)
			exit(1);
	}
	else
	{
		byte = 0;
		if (character != MESSAGE_END)
			client_pid[char_count++] = character;
		else if (character == MESSAGE_END)
		{
			*state = 0;
			client_pid[char_count] = '\0';
			char_count = 0;
			if (print_message(&message, client_pid) == EXIT_FAILURE)
				exit(1);
		}
	}
}

//	function to handle the SIGUSR signals from the client
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
		if (character != MESSAGE_END && state == 0)
			rest_len = append_int(rest_len, ft_atoi(&character));
		else if (character == MESSAGE_END && state == 0)
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
