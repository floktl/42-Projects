/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 07:30:11 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/21 13:17:45 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal()
{
	std::cout << "Animal has been created!" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal &other)
{
	Animal::type = other.type;
}

//copy assignment constructor
Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		type = other.getType();
	}
	return (*this);
}

// Deconstructor
Animal::~Animal()
{
	std::cout << "Animal has been destroyed!" << std::endl;
}

// Getter for type
std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
        std::cout << "Some animal sound!" << std::endl;
}
