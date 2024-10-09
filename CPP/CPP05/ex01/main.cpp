/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:16:29 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/05 08:35:35 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try
    {
        // Create a valid Bureaucrat
        Bureaucrat john("John", 50);
        std::cout << john << std::endl;

        // Try incrementing and decrementing the grade
        john.incGrade(10);
        std::cout << "After increasing John's grade: " << john << std::endl;

        john.decGrade(20);
        std::cout << "After decreasing John's grade: " << john << std::endl;

        // Create a Form with valid grades
        Form taxForm("Tax Form", 30, 20);
        std::cout << taxForm << std::endl;

        // Try to sign the form with a Bureaucrat that has too low of a grade
        try
        {
            john.signForm(taxForm);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Create a higher-ranked Bureaucrat
        Bureaucrat alice("Alice", 25);
        std::cout << alice << std::endl;

        // Try signing the form with Alice, whose grade is high enough
        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;

        // Try to create a Form with an invalid high grade
        try
        {
            Form invalidForm("Invalid Form", 0, 20);
        }
        catch (std::exception& e)
        {
            std::cerr << "Error creating form: " << e.what() << std::endl;
        }

        // Try to create a Bureaucrat with an invalid grade
        try
        {
            Bureaucrat invalidBureaucrat("Invalid Bureaucrat", 151);
        }
        catch (std::exception& e)
        {
            std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "General exception: " << e.what() << std::endl;
    }

    return 0;
}
