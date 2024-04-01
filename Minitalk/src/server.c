/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:29:17 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/31 14:51:40 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

//	function to print the message using the write function for quicker response
int	print_message(char **message, char *client_pid)
{
	int	i;

	i = 0;
	if (kill((pid_t)ft_atoi(client_pid), SIGUSR1) == -1)
	{
		ft_printf("\033[0;31merror sending signal\033[0m\n");
		client_pid = NULL;
		if (*message)
		{
			free(*message);
			*message = NULL;
		}
		return (EXIT_FAILURE);
	}
	ft_putstr_fd(*message, 1);
	free(*message);
	(*message) = NULL;
	return (EXIT_SUCCESS);
}

//	function to add one character to the message, reallocate memory
int	add_char(char **message, char character, int *rest_len)
{
	if (!(*message))
	{
		*message = (char *)ft_calloc(1, 1);
		(*message)[0] = '\0';
		if (!(*message))
			return (EXIT_FAILURE);
	}
	if (add_char_to_string(message, character) == -1)
		return (EXIT_FAILURE);
	(*rest_len)--;
	return (EXIT_SUCCESS);
}

//	function to output the current character or send the PID of the current
//	process to the client, to check if message is received
int	output_message(char character, int *state, int *rest_len)
{
	static int	pid_count = 0;
	static char	client_pid[6] = {0};
	static char	*message = NULL;

	if (*rest_len > 0)
	{
		if (add_char(&message, character, rest_len) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (character != MESSAGE_END)
			client_pid[pid_count++] = character;
		else if (character == MESSAGE_END)
		{
			*state = 0;
			client_pid[pid_count] = '\0';
			pid_count = 0;
			if (print_message(&message, client_pid) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
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
		{
			rest_len = append_int(rest_len, ft_atoi(&character));
		}
		else if (character == MESSAGE_END && state == 0)
			state = 1;
		else if (output_message(character, &state, &rest_len) == EXIT_FAILURE)
		{
			exit(1);
		}
	}
}

int	main(void)
{
	int	i;

	i = 0;
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	ft_printf("\033[0;33mServer PID: %d\033[0m\n\n", getpid());
	ft_printf("\033[0;33mwaiting for signals \033[0m");
	while (i++ < 5)
	{
		ft_printf("\033[0;33m.\033[0m");
		sleep(1);
	}
	ft_printf("\n");
	while (1)
	{
		pause();
	}
	return (0);
}

//volatile sig_atomic_t	g_done = 0;

//void	handle_timeout(int sig)
//{
//	(void)sig;
//	ft_printf("Timeout reached. Exiting loop...\n");
//	g_done = 1;
//}

//int	main(void)
//{
//	int	i;

//	i = 0;
//	signal(SIGUSR1, handle_sigusr);
//	signal(SIGUSR2, handle_sigusr);
//	signal(SIGALRM, handle_timeout);
//	ft_printf("\033[0;33mServer PID: %d\033[0m\n\n", getpid());
//	ft_printf("\033[0;33mwaiting for signals \033[0m");
//	while (i++ < 5)
//	{
//		ft_printf("\033[0;33m.\033[0m");
//		sleep(1);
//	}
//	while (!g_done)
//	{
//		pause();
//	}
//	g_done = 0;
//	return (0);
//}
