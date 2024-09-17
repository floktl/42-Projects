/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:09:39 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/16 07:30:02 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Fixed Point::getY( void ) const
{
    return y;
}

Fixed Point::getX( void ) const
{
    return x;
}



// Constructor
Point::Point(const float xVal, const float yVal) : x(xVal), y(yVal) {}


// Print function definition
void Point::print(std::ostream& os) const
{
    os << "(" << x.toFloat() << ", " << y.toFloat() << ")";
}

// Copy assignment operator
Point& Point::operator=(const Point& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		x = other.x;
		y = other.y;

	}
	return *this;
}

// Overloaded operator<< for printing Point
std::ostream& operator<<(std::ostream& os, const Point& point)
{
    point.print(os);
    return os;
}
