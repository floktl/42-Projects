/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:04:02 by flo               #+#    #+#             */
/*   Updated: 2024/08/12 11:37:06 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> // for roundf

class Fixed {
private:
	int					value;
	static const int	fractionalBits = 8;

public:
	// Default constructor
	Fixed() : value(0) {
		std::cout << "Default constructor called" << std::endl;
	}

	// Constructor from integer
	Fixed(int raw) : value(raw << fractionalBits) {
		std::cout << "Integer constructor called" << std::endl;
	}

	// Constructor from float
	Fixed(float raw) : value(static_cast<int>(roundf(raw * (1 << fractionalBits)))) {
		std::cout << "Float constructor called" << std::endl;
	}

	// Copy constructor
	Fixed(const Fixed& other) : value(other.value) {
		std::cout << "Copy constructor called" << std::endl;
	}

	// Copy assignment operator
	Fixed& operator=(const Fixed& other) {
		std::cout << "Copy assignment operator called" << std::endl;
		if (this != &other) { // Handle self-assignment
			value = other.value;
		}
		return *this;
	}

	// Destructor
	~Fixed() {
		std::cout << "Destructor called" << std::endl;
	}

	// Get raw bits
	int getRawBits(void) const {
		std::cout << "getRawBits member function called" << std::endl;
		return value;
	}

	// Set raw bits
	void setRawBits(int const raw) {
		value = raw;
	}

	// Convert to floating-point representation
	float toFloat(void) const {
		return static_cast<float>(value) / (1 << fractionalBits);
	}

	// Convert to integer representation
	int toInt(void) const {
		return value >> fractionalBits;
	}

	// operator overload functions
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;

	// comparison operators
	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	// Overload the insertion operator to print the fixed-point number
	void print(std::ostream& os) const {
		os << this->toFloat();
	}
};

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

#endif // FIXED_HPP
