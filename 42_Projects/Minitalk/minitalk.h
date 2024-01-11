/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:36:31 by fkeitel           #+#    #+#             */
/*   Updated: 2024/01/10 15:52:08 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//defining the header file
#ifndef MINITALK_H
# define MINITALK_H

//header files
# include <sys/types.h>
# include <sys/socket.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/un.h>
# include "libft.h"
# include <signal.h>
# define SERVER_SOCKET_PATH "/tmp/server_socket"
# include <sys/shm.h>
# include <stddef.h>
# include "libft/libft.h"
# include <stdarg.h>
# include <limits.h>

#endif