/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 08:59:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/05 07:11:42 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructor implementation
Bureaucrat::Bureaucrat(std::string const &name, int grade)
    : name(name), grade(grade)
{
    try
	{
        if (grade < 1)
            throw GradeTooHighException();
        else if (grade > 150)
            throw GradeTooLowException();
    }
	catch (std::exception& e)
	{
		//	it would make more sense to implement the error message directly here
        throw;
    }
}

// Increment grade
void Bureaucrat::incGrade(int num)
{
    try
	{
        if (grade - num < 1)
            throw GradeTooHighException();
        grade -= num; // Decrease grade because a lower number means higher rank
    } catch (std::exception& e)
	{
		//	it would make more sense to implement the error message directly here
        throw;
    }
}

// Decrement grade
void Bureaucrat::decGrade(int num)
{
    try
	{
        if (grade + num > 150)
            throw GradeTooLowException();
        grade += num;
    }
	catch (std::exception& e)
	{
		//	it would make more sense to implement the error message directly here
        throw;
    }
}


// Implementations for the custom exceptions
const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Bureaucrat::GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Bureaucrat::GradeTooLowException";
}

const char* Bureaucrat::what() const noexcept
{
    return "Bureaucrat general exception occurred";
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

void Bureaucrat::print(std::ostream& os) const
{
    os << this->getName() << ", bureaucrat grade " << getGrade() << std::endl;
}

// Non-member function to overload the insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat)
{
    Bureaucrat.print(os);
    return os;
}
