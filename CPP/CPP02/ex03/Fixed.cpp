/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:30:41 by flo               #+#    #+#             */
/*   Updated: 2024/09/15 12:47:02 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//----------------------------- Default settings-------------------------------

// Default constructor
Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Constructor from integer
Fixed::Fixed(int raw) : value(raw << fractionalBits)
{
	std::cout << "Integer constructor called" << std::endl;
}

// Constructor from float
Fixed::Fixed(float raw) : value(static_cast<int>(roundf(raw * (1 << fractionalBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other) : value(other.value)
{
	std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		value = other.value;
	return *this;
}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

//-------------------------------  functions --------------------------------

// Get raw bits
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

// Set raw bits
void Fixed::setRawBits(int const raw)
{
	value = raw;
}

// Convert to floating-point representation
float Fixed::toFloat(void) const
{
	return static_cast<float>(value) / (1 << fractionalBits);
}

// Convert to integer representation
int Fixed::toInt(void) const {
	return value >> fractionalBits;
}

// Overload the insertion operator to print the fixed-point number
void Fixed::print(std::ostream& os) const
{
	os << this->toFloat();
}

//------------------------- overload functions --------------------------------

// Non-member function to overload the insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	fixed.print(os);
	return os;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits((this->getRawBits() * other.getRawBits()) >> Fixed::fractionalBits);
	return (result);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits((this->getRawBits() + other.getRawBits()) >> Fixed::fractionalBits);
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits((this->getRawBits() - other.getRawBits()) >> Fixed::fractionalBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits((this->getRawBits() / other.getRawBits()) >> Fixed::fractionalBits);
	return (result);
}

//	comparison overload functions

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->getRawBits() != other.getRawBits());
}

// incrememt values

// Pre-increment
Fixed& Fixed::operator++()
{
	this->value++; //+= (fractionalBits);
    return *this;
}

// Post-increment
Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->value++; // (fractionalBits);
    return temp;
}

// Pre-increment
Fixed& Fixed::operator--()
{
    this->value--; // (fractionalBits);
    return *this;
}

// Post-decrement
Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->value--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}
