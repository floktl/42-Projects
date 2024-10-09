/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 08:59:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/05 09:15:23 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

//------------------------- AForm Constructor --------------------------------
AForm::AForm(std::string const &name, int grade_sign, int grade_exec)
    : name(name), _signed(false), grade_sign(grade_sign), grade_exec(grade_exec)
{
    if (grade_sign < 1 || grade_exec < 1)
        throw GradeTooHighException();
    if (grade_sign > 150 || grade_exec > 150)
        throw GradeTooLowException();
}

//------------------------- Getter functions --------------------------------
std::string AForm::getName() const
{
    return name;
}

bool AForm::getSignedStatus() const
{
    return _signed;
}

int AForm::getGradeSigned() const
{
    return grade_sign;
}

int AForm::getGradeExec() const
{
    return grade_exec;
}

//------------------------- beSigned Function --------------------------------
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > grade_sign)
        throw GradeTooLowException();
    _signed = true;
}

//------------------------- Custom Exceptions Implementation --------------------------------
const char* AForm::GradeTooHighException::what() const noexcept
{
    return "AForm::GradeTooHighException";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
    return "AForm::GradeTooLowException!";
}

//------------------------- Print Function --------------------------------
void AForm::print(std::ostream& os) const
{
    os << "AForm name: " << getName()
	<< ", signed: " << (getSignedStatus() ? "Yes" : "No")
	<< ", grade required to sign: " << getGradeSigned()
	<< ", grade required to execute: " << getGradeExec() << std::endl;
}

//------------------------- Operator Overloading --------------------------------
std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    form.print(os);
    return os;
}

//------------------------- General Exception Override --------------------------------
const char* AForm::what() const noexcept
{
    return "AForm exception occurred!";
}
