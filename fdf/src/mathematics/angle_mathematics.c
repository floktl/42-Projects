/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_mathematics.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:36:46 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/09 06:57:58 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//
//----------- replacement for the angle fucntion (sin(), cos()) ---------------
//

//	This function calculates the factorial of a given number.
//	Factorial of a non-negative integer n, denoted by n!, is the product
//	of all positive integers less than or equal to n. (4! = 4 x 3 x 2 x 1 = 24)
double	factorial(double n)
{
	if (n == 0)
		return (1);
	return (n * (factorial(n - 1)));
}

//	This function calculates the power of a given number
//	to another given number (exponent).
//	For example, if n is the base and power is the exponent, it calcul. n^power.
double	power(double n, double power)
{
	double	result;
	int		i;

	result = n;
	i = 1;
	while (i++ < power)
		result = n * result;
	return (result);
}

//	function to replace the sin() function of math.h Taylor Series for Sine
//	cos(x)=x - x^3/3! + x^5/5! - x^7/7! + ...
double	ft_sin(double x)
{
	double	result;
	double	coefficent;
	double	pow;
	double	frac;
	int		i;

	result = x;
	coefficent = 3.0;
	i = 0;
	while (i < 10)
	{
		pow = power(x, coefficent);
		frac = factorial(coefficent);
		if (i % 2 == 0)
			result = result - (pow / frac);
		else
			result = result + (pow / frac);
		coefficent = coefficent + 2;
		i++;
	}
	return (result);
}

//	function to replace the cos() function from math.h Taylor Series for Cosine
//	cos(x)=1− x^2/2! + x^4/4! - x^6/6! + ...
double	ft_cos(double x)
{
	double	result;
	double	term ;
	int		sign;
	int		n;

	result = 1.0;
	term = 1.0;
	sign = -1;
	n = 2;
	while (n < 20)
	{
		term = power(x, n) / factorial(n);
		result += sign * term;
		sign = -sign;
		n += 2;
	}
	return (result);
}
