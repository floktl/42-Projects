/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:25:37 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/21 14:00:09 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat() :Animal(), brain(new Brain())
{
	Cat::type = "Cat";
	std::cout << type << " has been created!" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat &other) :Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Cat copied!" << std::endl;
}

// copy assignment constructor
Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

// Deconstructor
Cat::~Cat()
{
	delete brain;
	std::cout << "Cat has been brutally slaughtered!" << std::endl;
}

//member functions

void Cat::makeSound() const
{
	std::cout << "Miauuuuu!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return brain;
}
