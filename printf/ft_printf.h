/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:36:39 by fkeitel           #+#    #+#             */
/*   Updated: 2023/12/20 12:30:05 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
//Project "printf" from the 42 core curriculum, which is a simplified replicate-
// of the "printf" funtion in C
//

//defining the header file
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
//including different libraries
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <stdarg.h>

//main function for printing
int	ft_printf(const char *format, ...);

//checking which datatypes are given
int	ft_checkcases(const char format, va_list argument);

//functions for handling special data formats
int	put_u(unsigned int n);
int	put_hex(unsigned long *hexadecimal, int upper_lower, int counter);
int	put_i(int n, int counter);
int	put_p(va_list argument);

//functions for the actual printing
int	ft_printstr(char *str, int counter);
int	ft_putchar(int c, int counter);

#endif
