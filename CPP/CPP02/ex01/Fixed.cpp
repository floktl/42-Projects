/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:52:49 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/13 09:01:10 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Constructor from integer
Fixed::Fixed(int const raw) : value(raw << fractionalBits)
{
    std::cout << "Integer constructor called" << std::endl;
}

// Constructor from float
Fixed::Fixed(float const raw) : value(static_cast<int>(roundf(raw * (1 << fractionalBits))))
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
	{ // Handle self-assignment
        value = other.value;
    }
    return *this;
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

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
int Fixed::toInt(void) const
{
    return value >> fractionalBits;
}

// Public accessor for internal value
int Fixed::getValue() const
{
    return value;
}

// Non-member function to overload the insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
