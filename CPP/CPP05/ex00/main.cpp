/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:16:29 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/05 07:04:25 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
	{
        Bureaucrat a("hello", 150);
		std::cout << a << std::endl;
        Bureaucrat b("hello", 1);
		std::cout << b << std::endl;
        //a.decGrade(1); // This will throw GradeTooLowException
		//b.incGrade(1); // This will throw GradeTooHighException
		//Bureaucrat c("hello", 151); // invalid, grade too low
		//std::cout << c << std::endl;
		Bureaucrat d("hello", 0); // invalid, grade too high
		std::cout << d << std::endl;
    }
	catch (const Bureaucrat::GradeTooHighException& e)
	{
        std::cerr << e.what() << std::endl;
    }
	catch (const Bureaucrat::GradeTooLowException& e)
	{
        std::cerr << e.what() << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
