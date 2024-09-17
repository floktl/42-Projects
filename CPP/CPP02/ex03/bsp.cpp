/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:03:37 by flo               #+#    #+#             */
/*   Updated: 2024/09/16 07:33:29 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include "Point.hpp"

#include "Point.hpp"
#include <cmath>

//	my own implication of the fabsf() function
float myFabsf(float value)
{
    return value < 0.0f ? -value : value;
}

// Function to calculate the signed area of the triangle
float area(const Point& p1, const Point& p2, const Point& p3)
{
    return myFabsf((p1.getX().toFloat() * (p2.getY().toFloat()
		- p3.getY().toFloat())) +
        (p2.getX().toFloat() * (p3.getY().toFloat()
		- p1.getY().toFloat())) +
        (p3.getX().toFloat() * (p1.getY().toFloat()
		- p2.getY().toFloat()))) / 2.0;
}

// BSP function to check if the point is inside the triangle
bool bsp(const Point& a, const Point& b, const Point& c, const Point& point)
{
    // Compute areas
    float totalArea = area(a, b, c);
    float area1 = area(point, b, c);
    float area2 = area(a, point, c);
    float area3 = area(a, b, point);

    // If the sum of the areas of the sub-triangles is equal to the area of the whole triangle
    // The point lies inside the triangle (or on its edge).
    return myFabsf(totalArea - (area1 + area2 + area3)) < 0.00001;
}

