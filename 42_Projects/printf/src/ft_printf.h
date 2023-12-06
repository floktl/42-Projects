/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:36:39 by fkeitel           #+#    #+#             */
/*   Updated: 2023/11/24 19:45:04 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include <stdarg.h>

int	ft_checkcases(const char format, va_list argument, int counter);

int	ft_putunbr(unsigned int n, int fd);

int	ft_printf(const char *format, ...);

int	ft_puthex(unsigned long *hexadecimal, int upper_lower, int counter);

int	ft_putnbrui(int n, int fd, int counter);

int	ft_printstr(char *str, int counter);

int	ft_putchar(int c, int fd, int counter);

#endif
