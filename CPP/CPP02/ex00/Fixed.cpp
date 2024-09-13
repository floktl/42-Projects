/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 07:30:11 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/13 07:41:06 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed.cpp
#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

// Default constructor
Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    value = other.getRawBits();
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        value = other.getRawBits();
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
