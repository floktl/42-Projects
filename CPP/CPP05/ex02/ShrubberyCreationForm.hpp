/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 08:56:22 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/05 09:22:18 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <exception>
#include <string>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
public:


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
std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& form);

#endif
