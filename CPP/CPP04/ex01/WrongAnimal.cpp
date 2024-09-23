/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 07:30:11 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/21 09:00:00 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal has been created!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal has been destroyed!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	WrongAnimal::type = other.type;
}

// Getter for type
std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
        std::cout << "Some Wrong animal sound!" << std::endl;
}
