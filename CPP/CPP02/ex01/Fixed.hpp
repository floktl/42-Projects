/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:04:02 by flo               #+#    #+#             */
/*   Updated: 2024/09/13 08:58:51 by fkeitel          ###   ########.fr       */
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
    Fixed();
    Fixed(int const raw);
    Fixed(float const raw);
    // Copy constructor
    Fixed(const Fixed& other);
    // Copy assignment operator
    Fixed& operator=(const Fixed& other);
    // Destructor
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    int getValue() const;
};

// Non-member function to overload the insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
