/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:30:41 by flo               #+#    #+#             */
/*   Updated: 2024/08/12 11:35:02 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Non-member function to overload the insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
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
