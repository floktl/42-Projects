/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:04:02 by flo               #+#    #+#             */
/*   Updated: 2024/09/13 13:35:57 by fkeitel          ###   ########.fr       */
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
	Fixed();

	// Constructor from integer
	Fixed(int raw);
	// Constructor from float
	Fixed(float raw);
	// Copy constructor
	Fixed(const Fixed& other);

	// Copy assignment operator
	Fixed& operator=(const Fixed& other);

	// Destructor
	~Fixed();

	// Get raw bits
	int getRawBits(void) const;

	// Set raw bits
	void setRawBits(int const raw);

	// Convert to floating-point representation
	float toFloat(void) const;

	// Convert to integer representation
	int toInt(void) const;

	// Overload the insertion operator to print the fixed-point number
	void print(std::ostream& os) const;

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

	Fixed operator++(int);
	Fixed &operator++();
	Fixed operator--(int);
	Fixed &operator--();

	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

#endif // FIXED_HPP
