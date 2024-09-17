/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:30:15 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/15 18:10:22 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib> // For std::stof
#include "Point.hpp"

int main(int argc, char **argv)
{
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);
    bool result;

    // Output file for coordinates
    std::ofstream outputFile("coordinates.txt");
    if (!outputFile)
    {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    // Write triangle vertices to file
    outputFile << a.getX().toFloat() << " " << a.getY().toFloat() << std::endl;
    outputFile << b.getX().toFloat() << " " << b.getY().toFloat() << std::endl;
    outputFile << c.getX().toFloat() << " " << c.getY().toFloat() << std::endl;

    if (argc == 1)
    {
        Point inside(2.5f, 1.0f);
        result = bsp(a, b, c, inside);
        outputFile << inside.getX().toFloat() << " " << inside.getY().toFloat() << std::endl;
        outputFile << (result ? "inside" : "outside") << std::endl;

        // Additional points
        Point outside(5.0f, 5.0f);
        result = bsp(a, b, c, outside);
        outputFile << outside.getX().toFloat() << " " << outside.getY().toFloat() << std::endl;
        outputFile << (result ? "inside" : "outside") << std::endl;

        Point edge(2.5f, 0.0f);
        result = bsp(a, b, c, edge);
        outputFile << edge.getX().toFloat() << " " << edge.getY().toFloat() << std::endl;
        outputFile << (result ? "inside" : "outside") << std::endl;

        Point vertex(0.0f, 0.0f);
        result = bsp(a, b, c, vertex);
        outputFile << vertex.getX().toFloat() << " " << vertex.getY().toFloat() << std::endl;
        outputFile << (result ? "inside" : "outside") << std::endl;
    }
    else if (argc == 3)
    {
        try
        {
            float x = std::stof(argv[1]);
            float y = std::stof(argv[2]);
            Point own(x, y);
            result = bsp(a, b, c, own);
            outputFile << own.getX().toFloat() << " " << own.getY().toFloat() << std::endl;
            outputFile << (result ? "inside" : "outside") << std::endl;
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << "Invalid argument: " << e.what() << std::endl;
            return 1;
        }
        catch (const std::out_of_range& e)
        {
            std::cerr << "Out of range: " << e.what() << std::endl;
            return 1;
        }
    }
    else
    {
        std::cerr << "Usage: " << argv[0] << " [x y]" << std::endl;
        return 1;
    }

    // Close the file
    outputFile.close();

    return 0;
}
