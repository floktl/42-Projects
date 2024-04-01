/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:36:31 by fkeitel           #+#    #+#             */
/*   Updated: 2024/03/31 08:49:12 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//defining the header file
#ifndef MINITALK_H
# define MINITALK_H

//	indicator, that the message starts after the PID
# define MESSAGE_END 'a'

//header files
# include <sys/types.h>
# include <sys/socket.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/un.h>
# include <signal.h>
# include <sys/shm.h>
# include <stddef.h>
# include "libft/libft.h"
# include <stdarg.h>
# include <limits.h>
# include <sys/types.h>
# include <unistd.h>

#endif
