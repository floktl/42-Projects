/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:00:58 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/16 07:29:49 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include "Fixed.hpp"

class Point {
private:
	Fixed	x;
	Fixed	y;
public:
	Point() = default;
	Point(const float x, const float y);
	Point(const Point& other) = default;
	Point& operator=(const Point& other);
	~Point() = default;
	void print(std::ostream& os) const;
	Fixed getX() const;
	Fixed getY() const;
};



bool bsp(const Point& a, const Point& b, const Point& c, const Point& point);
std::ostream& operator<<(std::ostream& os, const Point& point);

#endif
