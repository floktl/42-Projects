/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:00:23 by fkeitel           #+#    #+#             */
/*   Updated: 2024/06/28 17:28:03 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * function to convert a string into an integer including + and
 * - signs
 *
 * @param str the string to convert
 * @return the converted integer
 */
int	ft_atoi(const char *str)
{
	int	sign;
	int	count;
	int	result;

	sign = 1;
	count = 0;
	result = 0;
	while (str[count] == ' ' || (str[count] >= '\t' && str[count] <= '\r'))
		count++;
	if (str[count] == '-')
		sign = -1;
	if (str[count] == '-' || str[count] == '+')
		count++;
	while (str[count] >= '0' && str[count] <= '9')
	{
		while (ft_isdigit(str[count]))
		{
			result *= 10;
			result += str[count] - '0';
			count++;
		}
	}
	return (result * sign);
}

/*int main() {
    char str[] = "12345"; // Replace this with the string you want to convert
    int number = ft_atoi(str);

    printf("String: %s\n", str);
    printf("Converted to Integer: %d\n", number);

    return 0;
}*/
