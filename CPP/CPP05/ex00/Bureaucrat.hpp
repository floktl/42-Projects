/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 08:56:22 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/04 10:33:56 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>
#include <iostream>

class Bureaucrat : public std::exception
{
private:
    const std::string name;
    int grade;

public:
    // Custom exceptions within the Bureaucrat class
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

    Bureaucrat(std::string const &name, int grade);

    std::string getName() const;
    int getGrade() const;

    void incGrade(int num);
    void decGrade(int num);

	void print(std::ostream& os) const;
    // Override the what() function for general exceptions
    const char* what() const noexcept override;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif