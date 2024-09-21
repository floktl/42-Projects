/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 07:30:11 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/20 12:44:34 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal has been created!" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal has been destroyed!" << std::endl;
}

Animal::Animal(const Animal &other)
{
	Animal::type = other.type;
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
