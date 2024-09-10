/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:04:02 by flo               #+#    #+#             */
/*   Updated: 2024/07/26 12:37:03 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	private:
		int value;
		static const int fractionalBits = 8;

	public:
		// Default constructor
		Fixed() : value(0)
		{
			std::cout << "Default constructor called" << std::endl;
		}
		// Copy constructor
		Fixed(const Fixed& other)
		{
			std::cout << "Copy constructor called" << std::endl;
			value = other.getRawBits();
		}
		// Copy assignment operator
		Fixed& operator=(const Fixed& other)
		{
			std::cout << "Copy assignment operator called" << std::endl;
			value = other.getRawBits();
			return *this;
		}
		// Destructor
		~Fixed()
		{
			std::cout << "Destructor called" << std::endl;
		}
		// Get raw bits
		int getRawBits(void) const
		{
			std::cout << "getRawBits member function called" << std::endl;
			return value;
		}
		// Set raw bits
		void setRawBits(int const raw)
		{
			value = raw;
		}
};
