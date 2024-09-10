/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:04:02 by flo               #+#    #+#             */
/*   Updated: 2024/07/26 13:18:57 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> // for std::round

class Fixed {
private:
	int value;
	static const int fractionalBits = 8;

public:
	// Default constructor
	Fixed() : value(0)
	{
		std::cout << "Default constructor called" << std::endl;
	}
	// Constructor from integer
	Fixed(int const raw) : value(raw << fractionalBits)
	{
		std::cout << "Integer constructor called" << std::endl;
	}
	// Constructor from float
	Fixed(float const raw) : value(static_cast<int>(roundf(raw * (1 << fractionalBits))))
	{
		std::cout << "Float constructor called" << std::endl;
	}
	// Copy constructor
	Fixed(const Fixed& other) : value(other.value) {
		std::cout << "Copy constructor called" << std::endl;
	}

	// Copy assignment operator
	Fixed& operator=(const Fixed& other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		if (this != &other) { // Handle self-assignment
			value = other.value;
		}
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
	// Convert to floating-point representation
	float toFloat(void) const
	{
		return static_cast<float>(value) / (1 << fractionalBits);
	}
	// Convert to integer representation
	int toInt(void) const
	{
		return value >> fractionalBits;
	}
	// Public accessor for internal value
	int getValue() const
	{
		return value;
	}
};

// Non-member function to overload the insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

#endif
