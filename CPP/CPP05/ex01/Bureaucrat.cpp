/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 08:59:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/05 08:33:47 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

//------------------------- Bureaucrat Constructor --------------------------------
Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

//------------------------- Getter functions --------------------------------
std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

//------------------------- Grade Adjustment --------------------------------
void Bureaucrat::incGrade(int num)
{
    if (grade - num < 1)
        throw GradeTooHighException();
    grade -= num;
}

void Bureaucrat::decGrade(int num)
{
    if (grade + num > 150)
        throw GradeTooLowException();
    grade += num;
}

//------------------------- signForm Function --------------------------------
void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << name << " couldn’t sign " << form.getName()
			<< " because " << e.what() << std::endl;
    }
}

//------------------------- Custom Exceptions Implementation --------------------------------
const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Form::GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Form::GradeTooLowException";
}

//------------------------- Print Function --------------------------------
void Bureaucrat::print(std::ostream& os) const
{
    os << this->getName() << ", bureaucrat grade " << getGrade() << std::endl;
}

//------------------------- Operator Overloading --------------------------------
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    bureaucrat.print(os);
    return os;
}

//------------------------- General Exception Override --------------------------------
const char* Bureaucrat::what() const noexcept
{
    return "Bureaucrat exception occurred!";
}
