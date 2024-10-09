/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 08:56:22 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/05 08:28:50 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form : public std::exception
{
private:
    const std::string name;
    bool _signed;
    const int grade_sign;
    const int grade_exec;

public:
    // Custom exceptions within the Form class
    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const noexcept override;
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const noexcept override;
    };

    Form(std::string const &name, int grade_sign, int grade_exec);

    std::string getName() const;
    bool getSignedStatus() const;
    int getGradeSigned() const;
    int getGradeExec() const;

    void beSigned(const Bureaucrat& bureaucrat);

    void print(std::ostream& os) const;

    // Override the what() function for general exceptions
    const char* what() const noexcept override;
};

// Non-member function to overload the insertion operator
std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
